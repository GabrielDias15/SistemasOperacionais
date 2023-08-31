#include <stdio.h>

int posicaoCaracter(char str[], char c) {
  for(int i=0; str[i] != '\0'; i++) {
    if(str[i] == c)
      return i;
  }
  return -1; // Não encontrou
}

int main() {
  char texto[100];
  char caractere;

  printf("Digite uma string: ");
  scanf("%s", texto);

  printf("Digite o caractere que deseja buscar: ");
  scanf(" %c", &caractere); // Inserindo um espaço antes do %c para ignorar espaços e caracteres de nova linha

  int posicao = posicaoCaracter(texto, caractere);

  if (posicao != -1) {
    printf("O caractere '%c' foi encontrado na posição %d da string.\n", caractere, posicao);
  } else {
    printf("O caractere '%c' não foi encontrado na string.\n", caractere);
  }

  return 0;
}
