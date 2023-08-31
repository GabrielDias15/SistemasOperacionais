#include <stdio.h>

int main() {
  int m, n, matriz[10][10], transp[10][10];

  printf("Digite o número de linhas e colunas da matriz: ");
  scanf("%d %d", &m, &n);

  printf("Digite os elementos da matriz:\n");

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      transp[j][i] = matriz[i][j];
    }
  }

  printf("Matriz transposta:\n");

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      printf("%d ", transp[i][j]); 
    }
    printf("\n");
  }

  return 0;
}
