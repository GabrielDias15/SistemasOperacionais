#include <stdio.h>

#define COLS 3

void sum_rows(int L1, int L2, int matrix[][COLS], int rows){
    for(int i=0; i<rows; i++){
        matrix[L2][i] += matrix[L1][i];
    }
}

void mul_rows(int L1, int L2, int matrix[][COLS], int rows){
    for(int i=0; i<rows; i++){
        matrix[L2][i] *= matrix[L1][i];
    }
}

int main(){
    int matrix[3][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sum_rows(0, 1, matrix, COLS);
    mul_rows(0, 2, matrix, COLS);
    
    // printing the matrix
    for(int i=0; i<3; i++){
        for(int j=0; j<COLS; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}