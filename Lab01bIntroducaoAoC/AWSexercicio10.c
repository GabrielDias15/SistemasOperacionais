#include <stdio.h>

void multiplicaLinha(int matriz[][10], int lin, int col, int num, int linha) {
  for(int j=0; j<col; j++) {
    matriz[linha][j] *= num;
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

  int linha, numero;

  printf("Digite o número da linha que deseja multiplicar: ");
  scanf("%d", &linha);

  printf("Digite o número pelo qual deseja multiplicar a linha: ");
  scanf("%d", &numero);

  multiplicaLinha(matriz, linhas, colunas, numero, linha);

  printf("Matriz após a multiplicação da linha:\n");
  for(int i=0; i<linhas; i++) {
    for(int j=0; j<colunas; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
