#include <stdio.h>

void multiplicaColuna(int matriz[][10], int lin, int col, int num, int coluna) {
  for(int i=0; i<lin; i++) {
    matriz[i][coluna] *= num; 
  }
}

int main() {
  int linhas, colunas;

  printf("Digite o número de linhas da matriz: ");
  scanf("%d", &linhas);

  printf("Digite o número de colunas da matriz: ");
  scanf("%d", &colunas);

  int matriz[10][10];

  printf("Digite os elementos da matriz:\n");
  for(int i=0; i<linhas; i++) {
    for(int j=0; j<colunas; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  int coluna, numero;

  printf("Digite o número da coluna que deseja multiplicar: ");
  scanf("%d", &coluna);

  printf("Digite o número pelo qual deseja multiplicar a coluna: ");
  scanf("%d", &numero);

  multiplicaColuna(matriz, linhas, colunas, numero, coluna);

  printf("Matriz após a multiplicação da coluna:\n");
  for(int i=0; i<linhas; i++) {
    for(int j=0; j<colunas; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
