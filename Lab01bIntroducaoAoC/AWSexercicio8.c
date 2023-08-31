#include <stdio.h>

void transposta(int matriz[][10], int lin, int col) {
  int transp[10][10];

  for(int i=0; i<lin; i++) {
    for(int j=0; j<col; j++) {
      transp[j][i] = matriz[i][j];
    }
  }

  printf("Matriz transposta:\n");

  for(int i=0; i<col; i++) {
    for(int j=0; j<lin; j++) {
      printf("%d ", transp[i][j]);
    }
    printf("\n");
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

  transposta(matriz, linhas, colunas);

  return 0;
}
