#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PEOPLE 300000

typedef struct {
    int entrance_time;
    int direction;
} Person;

Person direction_0[MAX_PEOPLE];
Person direction_1[MAX_PEOPLE];
int size_0 = 0;
int size_1 = 0;
Person people[MAX_PEOPLE];
int people_count = 0;

void append(Person list[], int *size, Person p) {
    list[(*size)++] = p;
}

int process_people() {
    int final_arrival_time = 0;
    int current_index = 0;

    while (current_index < people_count) {
        Person current_person = people[current_index++];
        int entrance_time = current_person.entrance_time;
        int direction = current_person.direction;
        Person *active_list = (direction == 0) ? direction_0 : direction_1;
        int *active_size = (direction == 0) ? &size_0 : &size_1;

        int arrival_time = entrance_time + 10;
        append(active_list, active_size, current_person);

        int i, found;
        while (1) {
            found = 0;
            for (i = current_index; i < people_count; i++) {
                if (people[i].direction == direction && people[i].entrance_time <= arrival_time) {
                    append(active_list, active_size, people[i]);
                    arrival_time = (people[i].entrance_time + 10 > arrival_time) ? people[i].entrance_time + 10 : arrival_time;
                    for (int j = i; j < people_count - 1; j++) {
                        people[j] = people[j + 1];
                    }
                    people_count--;
                    i--;
                    found = 1;
                }
            }

            if (!found) {
                for (i = current_index; i < people_count; i++) {
                    if (people[i].direction != direction && people[i].entrance_time <= arrival_time) {
                        direction = people[i].direction;
                        active_list = (direction == 0) ? direction_0 : direction_1;
                        active_size = (direction == 0) ? &size_0 : &size_1;
                        append(active_list, active_size, people[i]);
                        arrival_time += 10;
                        for (int j = i; j < people_count - 1; j++) {
                            people[j] = people[j + 1];
                        }
                        people_count--;
                        found = 1;
                        break;
                    }
                }
            }

            if (!found) {
                break;
            }
        }

        final_arrival_time = (final_arrival_time > arrival_time) ? final_arrival_time : arrival_time;
    }

    return final_arrival_time;
}

int cmpfunc(const void * a, const void * b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;
    return ( personA->entrance_time - personB->entrance_time );
}

void read_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    for (int i = 0; i < people_count; i++) {
        if (fscanf(file, "%d %d", &people[i].entrance_time, &people[i].direction) != 2) {
            fprintf(stderr, "Erro lendo os dados para a pesoa %d no arquivo %s\n", i + 1, filename);
            fclose(file);
            exit(1);
        }

        if (people[i].entrance_time < 0 || (people[i].direction != 0 && people[i].direction != 1)) {
            fprintf(stderr, "Dados invalidos para a pessoa %d no arquivo %s\n", i + 1, filename);
            fclose(file);
            exit(1);
        }
    }

    fclose(file);
}


int check_output(const char *output_file, int result) {
    FILE *file = fopen(output_file, "r");
    if (file == NULL) {
        perror("Erro abrindo arquivo");
        return 0;
    }

    int expected;
    fscanf(file, "%d", &expected);
    fclose(file);

    return expected == result;
}

void process_directory(const char *input_dir, const char *output_dir) {
    DIR *dir;
    struct dirent *ent;
    char input_path[512], output_path[512];
    struct stat statbuf;

    dir = opendir(input_dir);
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((ent = readdir(dir)) != NULL) {
        snprintf(input_path, sizeof(input_path), "%s/%s", input_dir, ent->d_name);


        if (stat(input_path, &statbuf) == -1) {
            perror("Failed to get file status");
            continue;
        }

        if (S_ISREG(statbuf.st_mode)) {
            if (strlen(output_dir) + strlen(ent->d_name) + 1 < sizeof(output_path)) {
                snprintf(output_path, sizeof(output_path), "%s/%s", output_dir, ent->d_name);
            } else {
                fprintf(stderr, "Path too long: %s/%s\n", output_dir, ent->d_name);
                continue;
            }

            printf("Processing %s...\n", input_path);
            read_from_file(input_path);
            qsort(people, people_count, sizeof(Person), cmpfunc);
            int final_time = process_people();

            if (check_output(output_path, final_time)) {
                printf("Result for %s is correct.\n\n", ent->d_name);
            } else {
                printf("Result for %s is incorrect.\n\n", ent->d_name);
            }
        }
    }

    closedir(dir);
}

int main() {
    int choice;
    printf("\nEscolha:\n");
    printf("1. Processar apenas um arquivo\n");
    printf("2. Processar todos os arquivos das pastas input e output\n");
    scanf("%d", &choice);

    if (choice == 1) {
        char input_file[100], output_file[100];
        printf("Nome do arquivo de  input: ");
        scanf("%s", input_file);
        printf("Nome do arquivo de output: ");
        scanf("%s", output_file);

        read_from_file(input_file);
        qsort(people, people_count, sizeof(Person), cmpfunc);
        int final_time = process_people();
        if (check_output(output_file, final_time)) {
            printf("Output condiz com o resultado!:\n");
            printf("Tempo calculado:\n");
            printf(final_time);
            printf("Tempo do arquivo de output:\n");
            printf(output_file);

            
        } else {
            printf("Output nao condiz com o resultado!:\n");
            printf("Tempo calculado:\n");
            printf(final_time);
            printf("Tempo do arquivo de output:\n");
            printf(output_file);        }
    } else if (choice == 2) {
        process_directory("input", "output");
    }

    return 0;
}

