#include <stdio.h>

struct poly {
    int coeff;
    int expo;
};

int main() {
    struct poly p1[10], p2[10], p3[20];
    int m, n, i, j, k = 0;

    printf("Enter the number of terms of the first polynomial: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        printf("Enter the coeff and expo for term %d: ", i + 1);
        scanf("%d %d", &p1[i].coeff, &p1[i].expo);
    }

    printf("Enter the number of terms of the second polynomial: ");
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
        printf("Enter the coeff and expo for term %d: ", j + 1);
        scanf("%d %d", &p2[j].coeff, &p2[j].expo);
    }
    i = 0;
    j = 0;
    while (i < m && j < n) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++; j++; k++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k] = p1[i];
            i++; k++;
        } else {
            p3[k] = p2[j];
            j++; k++;
        }
    }
    while (i < m) {
        p3[k] = p1[i];
        i++; k++;
    }
    while (j < n) {
        p3[k] = p2[j];
        j++; k++;
    }
    printf("Sum of the polynomials: ");
    for (i = 0; i < k; i++) {
        if (p3[i].coeff == 0)
            continue;

        if (i > 0 && p3[i].coeff > 0)
            printf(" + ");

        printf("%dx^%d", p3[i].coeff, p3[i].expo);
    }
    printf("\n");

    return 0;
}
