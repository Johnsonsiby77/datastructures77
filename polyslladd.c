#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int expo;
    struct Node* next;
} Node;

Node* createNode(int coeff, int expo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, int coeff, int expo) {
    Node* newNode = createNode(coeff, expo);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node** lastPtr = &result;

    while (poly1 && poly2) {
        if (poly1->expo == poly2->expo) {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                *lastPtr = createNode(sumCoeff, poly1->expo);
                lastPtr = &((*lastPtr)->next);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->expo > poly2->expo) {
            *lastPtr = createNode(poly1->coeff, poly1->expo);
            lastPtr = &((*lastPtr)->next);
            poly1 = poly1->next;
        } else {
            *lastPtr = createNode(poly2->coeff, poly2->expo);
            lastPtr = &((*lastPtr)->next);
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        *lastPtr = createNode(poly1->coeff, poly1->expo);
        lastPtr = &((*lastPtr)->next);
        poly1 = poly1->next;
    }

    while (poly2) {
        *lastPtr = createNode(poly2->coeff, poly2->expo);
        lastPtr = &((*lastPtr)->next);
        poly2 = poly2->next;
    }

    return result;
}

void printPolynomial(Node* poly) {
    if (!poly) {
        printf("0\n");
        return;
    }

    while (poly) {
        printf("%dx^%d", poly->coeff, poly->expo);
        if (poly->next)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

void freePolynomial(Node* poly) {
    Node* temp;
    while (poly) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

void inputPolynomial(Node** poly) {
    int n, coeff, expo;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    printf("Enter each term as coefficient and exponent :\n");
    for (int i = 0; i < n; i++) {
        printf("Coefficient- Term %d: ", i+1);
        scanf("%d", &coeff);
        printf("Exponent-Term %d: ", i+1);
        scanf("%d", &expo);
        insertEnd(poly, coeff, expo);
    }
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    printf("First Polynomial :\n");
    inputPolynomial(&poly1);

    printf("\nSecond Polynomial :\n");
    inputPolynomial(&poly2);

    printf("\nPolynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    Node* result = addPolynomials(poly1, poly2);

    printf("Sum: ");
    printPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}

