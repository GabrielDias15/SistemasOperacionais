#include <stdio.h>

void modificaMatriz(int matriz[][10], int lin, int col) {
  for(int i=0; i<lin; i++) {
    for(int j=0; j<col; j++) {
      if(matriz[i][j] < 0) {
        matriz[i][j] = -matriz[i][j];
      }
    }
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

  modificaMatriz(matriz, linhas, colunas);

  printf("Matriz após a modificação:\n");
  for(int i=0; i<linhas; i++) {
    for(int j=0; j<colunas; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
