#include <stdio.h>

#define MAX_SIZE 100 
 
void addSparseMatrices(int matA[][3], int matB[][3], int result[][3], int sizeA, int sizeB) {
    int i = 0, j = 0, k = 0;

   
    while (i < sizeA && j < sizeB) {
    
        if (matA[i][0] < matB[j][0] || (matA[i][0] == matB[j][0] && matA[i][1] < matB[j][1])) {
            result[k][0] = matA[i][0];
            result[k][1] = matA[i][1];
            result[k][2] = matA[i][2];
            i++;
        } else if (matB[j][0] < matA[i][0] || (matB[j][0] == matA[i][0] && matB[j][1] < matA[i][1])) {
            result[k][0] = matB[j][0];
            result[k][1] = matB[j][1];
            result[k][2] = matB[j][2];
            j++;
        } else {
          
            result[k][0] = matA[i][0];
            result[k][1] = matA[i][1];
            result[k][2] = matA[i][2] + matB[j][2];
            i++;
            j++;
        }
        k++;
    }

  
    while (i < sizeA) {
        result[k][0] = matA[i][0];
        result[k][1] = matA[i][1];
        result[k][2] = matA[i][2];
        i++;
        k++;
    }

   
    while (j < sizeB) {
        result[k][0] = matB[j][0];
        result[k][1] = matB[j][1];
        result[k][2] = matB[j][2];
        j++;
        k++;
    }
}

int main() {
    int matA[MAX_SIZE][3], matB[MAX_SIZE][3], result[MAX_SIZE][3];
    int sizeA, sizeB;

   
    printf("Enter the number of non-zero elements in Matrix A: ");
    scanf("%d", &sizeA);

    printf("Enter the row, column and value for each non-zero element of Matrix A:\n");
    for (int i = 0; i < sizeA; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &matA[i][0], &matA[i][1], &matA[i][2]);
    }

 
    printf("Enter the number of non-zero elements in Matrix B: ");
    scanf("%d", &sizeB);

    printf("Enter the row, column and value for each non-zero element of Matrix B:\n");
    for (int i = 0; i < sizeB; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &matB[i][0], &matB[i][1], &matB[i][2]);
    }

 
    addSparseMatrices(matA, matB, result, sizeA, sizeB);

   
    printf("Resulting Sparse Matrix:\n");
    for (int i = 0; i < sizeA + sizeB; i++) {
        if (result[i][2] != 0) {
            printf("Row: %d, Col: %d, Value: %d\n", result[i][0], result[i][1], result[i][2]);
        }
    }

    return 0;
}


