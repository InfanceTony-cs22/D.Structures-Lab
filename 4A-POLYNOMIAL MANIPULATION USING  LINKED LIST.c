#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Structure to represent a linked list node for terms
struct Node {
    struct Term* data;
    struct Node* next;
};

// Function to create a new term with a given coefficient and exponent
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}
-------------------------------------------------------------
  // Function to add a new term to a polynomial
void addTerm(struct Term** polynomial, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);

    if (*polynomial == NULL || (*polynomial)->exponent < exponent) {
        newTerm->next = *polynomial;
        *polynomial = newTerm;
    } else {
        struct Term* current = *polynomial;
        while (current->next != NULL && current->next->exponent > exponent) {
            current = current->next;
        }
        newTerm->next = current->next;
        current->next = newTerm;
    }
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 != NULL && (poly2 == NULL || poly1->exponent > poly2->exponent)) {
            addTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly2 != NULL && (poly1 == NULL || poly2->exponent > poly1->exponent)) {
            addTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum_coeff = poly1->coefficient + poly2->coefficient;
            if (sum_coeff != 0) {
                addTerm(&result, sum_coeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    return result;
}

// Function to multiply a polynomial by a constant
void multiplyByConstant(struct Term* polynomial, int constant) {
    while (polynomial != NULL) {
        polynomial->coefficient *= constant;
        polynomial = polynomial->next;
    }
}

// Function to multiply two polynomials
struct Term* multiplyPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* temp = poly2;
    while (poly1 != NULL) {
        poly2 = temp;
        while (poly2 != NULL) {
            int product_coeff = poly1->coefficient * poly2->coefficient;
            int product_exp = poly1->exponent + poly2->exponent;
            addTerm(&result, product_coeff, product_exp);
            poly2 = poly2->next;
        }
        poly1 = poly1->next;
    }
    return result;
}

// Function to print a polynomial
void printPolynomial(struct Term* polynomial) {
    while (polynomial != NULL) {
        printf("%dx^%d", polynomial->coefficient, polynomial->exponent);
        if (polynomial->next != NULL) {
            printf(" + ");
        }
        polynomial = polynomial->next;
    }
    printf("\n");
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    addTerm(&poly1, 5, 2);
    addTerm(&poly1, 3, 1);
    addTerm(&poly1, 7, 0);

    addTerm(&poly2, 4, 2);
    addTerm(&poly2, -2, 1);
    addTerm(&poly2, 6, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    struct Term* sum = addPolynomials(poly1, poly2);
    printf("Sum of polynomials: ");
    printPolynomial(sum);

    multiplyByConstant(poly1, 2);
    printf("Polynomial 1
