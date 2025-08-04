#include <stdio.h>

#define MAX 100

typedef struct {
    int row, col, value;
} term;

typedef struct {
    term data[MAX];
    int rows, cols, terms;
} sparse_matrix;

// Function to add two sparse matrices
sparse_matrix add_sparse(sparse_matrix a, sparse_matrix b) {
    sparse_matrix sum;
    int i = 0, j = 0, k = 0;

    sum.rows = a.rows;
    sum.cols = a.cols;
    sum.terms = 0;

    while (i < a.terms && j < b.terms) {
        if (a.data[i].row < b.data[j].row ||
            (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col)) {
            sum.data[k++] = a.data[i++];
        } else if (a.data[i].row > b.data[j].row ||
            (a.data[i].row == b.data[j].row && a.data[i].col > b.data[j].col)) {
            sum.data[k++] = b.data[j++];
        } else {
            // Same position
            sum.data[k] = a.data[i];
            sum.data[k].value += b.data[j].value;
            i++; j++; k++;
        }
    }
    while (i < a.terms) sum.data[k++] = a.data[i++];
    while (j < b.terms) sum.data[k++] = b.data[j++];

    sum.terms = k;
    return sum;
}

// Function to transpose a sparse matrix
sparse_matrix transpose_sparse(sparse_matrix m) {
    sparse_matrix trans;
    trans.rows = m.cols;
    trans.cols = m.rows;
    trans.terms = m.terms;

    int k = 0;
    for (int col = 0; col < m.cols; col++) {
        for (int i = 0; i < m.terms; i++) {
            if (m.data[i].col == col) {
                trans.data[k].row = m.data[i].col;
                trans.data[k].col = m.data[i].row;
                trans.data[k].value = m.data[i].value;
                k++;
            }
        }
    }
    return trans;
}

// Example usage
int main() {
    sparse_matrix a, b, sum, trans;
    // Fill a and b with your matrix data here

    sum = add_sparse(a, b);
    trans = transpose_sparse(sum);

    // Print the transposed result
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < trans.terms; i++) {
        printf("%d\t%d\t%d\n", trans.data[i].row, trans.data[i].col, trans.data[i].value);
    }
    return 0;
}
