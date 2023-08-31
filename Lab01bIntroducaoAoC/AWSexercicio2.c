#include <stdio.h>

int main() {
  float n1, n2, n3, me, ma;
  char conceito;

  printf("Digite a primeira nota: ");
  scanf("%f", &n1);

  printf("Digite a segunda nota: ");
  scanf("%f", &n2);

  printf("Digite a terceira nota: ");
  scanf("%f", &n3);

  printf("Digite a média dos exercícios: ");
  scanf("%f", &me);

  ma = (n1 + n2 + n3 + me) / 7;

  if(ma >= 9) {
    conceito = 'A';
  } else if(ma >= 7.5) {
    conceito = 'B';
  } else if(ma >= 6) {
    conceito = 'C'; 
  } else if(ma >= 4) {
    conceito = 'D';
  } else {
    conceito = 'E';
  }

  printf("Média de aproveitamento: %.2f\n", ma);
  printf("Conceito: %c\n", conceito);

  return 0;
}
