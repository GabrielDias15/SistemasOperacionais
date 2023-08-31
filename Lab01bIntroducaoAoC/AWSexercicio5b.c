#include <stdio.h>

int main() {
  int m, n, matriz[10][10], num, coluna;

  printf("Digite o número de linhas e colunas da matriz: ");
  scanf("%d %d", &m, &n);

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      printf("Digite o elemento [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  printf("Digite o número da coluna: ");
  scanf("%d", &coluna);
  
  printf("Digite o número para multiplicar: ");
  scanf("%d", &num);

  for(int i=0; i<m; i++) {
    matriz[i][coluna] *= num;
  }

  printf("Matriz resultante:\n");

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
