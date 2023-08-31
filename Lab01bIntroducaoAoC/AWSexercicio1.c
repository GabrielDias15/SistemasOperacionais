#include <stdio.h>

int main() {
  int n, matriz[10][10], menor, linhaMenor;

  printf("Digite o tamanho da matriz quadrada: ");
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      printf("Digite o elemento [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  menor = matriz[0][0];
  linhaMenor = 0;

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(matriz[i][j] < menor) {
        menor = matriz[i][j];
        linhaMenor = i; 
      }
    }
  }

  printf("Linha com menor elemento: %d\n", linhaMenor);

  return 0;
}
