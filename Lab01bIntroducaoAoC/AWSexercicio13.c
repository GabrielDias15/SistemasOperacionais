#include <stdio.h>
#include <string.h>

void removeCaracter(char str[], int pos) {
  int i;
  for(i=pos; str[i] != '\0'; i++) {
    str[i] = str[i+1];
  }
  str[i] = '\0';
}

int main() {
  char texto[100];
  int posicao;

  printf("Digite uma string: ");
  scanf("%s", texto);

  printf("Digite a posição do caractere que deseja remover: ");
  scanf("%d", &posicao);

  if (posicao >= 0 && posicao < strlen(texto)) {
    removeCaracter(texto, posicao);
    printf("String após a remoção do caractere: %s\n", texto);
  } else {
    printf("Posição inválida.\n");
  }

  return 0;
}
