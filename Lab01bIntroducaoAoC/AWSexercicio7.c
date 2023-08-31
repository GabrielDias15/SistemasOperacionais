#include <stdio.h>

struct Pessoa {
  char nome[50];
  int idade;
  float peso;
  float altura;
};

int main() {
  struct Pessoa pessoa[3];

  for(int i=0; i<3; i++) {
    printf("Digite o nome: ");
    scanf("%s", pessoa[i].nome);

    printf("Digite a idade: ");
    scanf("%d", &pessoa[i].idade);

    printf("Digite o peso: ");
    scanf("%f", &pessoa[i].peso);

    printf("Digite a altura: ");
    scanf("%f", &pessoa[i].altura);
  }

  for(int i=0; i<3; i++) {
    printf("\nNome: %s", pessoa[i].nome);
    printf("\nIdade: %d", pessoa[i].idade);
    printf("\nPeso: %.2f", pessoa[i].peso);
    printf("\nAltura: %.2f", pessoa[i].altura);
  }

  return 0;
}
