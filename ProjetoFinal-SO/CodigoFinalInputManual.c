#include <stdio.h>
#include <stdlib.h>

#define MAX_PEOPLE 1000

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

        int i;
        while (1) {
            int found = 0;
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

int main() {
    printf("Numero de pessoas: ");
    scanf("%d", &people_count);

    for (int i = 0; i < people_count; i++) {
        printf("Tempo de entrada e direcao: ");
        scanf("%d %d", &people[i].entrance_time, &people[i].direction);
    }

    qsort(people, people_count, sizeof(Person), cmpfunc);

    printf("Tempo de chegada: %d\n", process_people());

    return 0;
}
