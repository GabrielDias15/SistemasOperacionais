#include <stdio.h>
#include <string.h>

int main() {
    char nome1[50], nome2[50];

    printf("Digite o primeiro nome: ");
    scanf("%s", nome1);

    printf("Digite o segundo nome: ");
    scanf("%s", nome2);

    if (strcmp(nome1, nome2) < 0) {
        printf("Nomes em ordem alfabética: %s, %s\n", nome1, nome2);
    } else {
        printf("Nomes em ordem alfabética: %s, %s\n", nome2, nome1);
    }

    return 0;
}
