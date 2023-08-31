#include <stdio.h>
#include <string.h>

void insereCaracter(char str[], int pos, char c) {
  int tam = strlen(str);
  for(int i=tam; i>=pos; i--) {
    str[i+1] = str[i];
  }
  str[pos] = c;
}

int main() {
  char texto[100];
  int posicao;
  char caractere;

  printf("Digite uma string: ");
  scanf("%s", texto);

  printf("Digite a posição em que deseja inserir o caractere: ");
  scanf("%d", &posicao);

  if (posicao >= 0 && posicao <= strlen(texto)) {
    printf("Digite o caractere que deseja inserir: ");
    scanf(" %c", &caractere); // Inserindo um espaço antes do %c para ignorar espaços e caracteres de nova linha

    insereCaracter(texto, posicao, caractere);

    printf("String após a inserção do caractere: %s\n", texto);
  } else {
    printf("Posição inválida.\n");
  }

  return 0;
}
