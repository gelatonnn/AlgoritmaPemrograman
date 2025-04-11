#include "polynomial.h"

void CreatePolynomial(Polynomial *P, int degree) {
    P->degree = degree;
    for (int i = 0; i <= degree; ++i) {
        P->coef[i] = 0;
    }
}

void ReadPolynomial(Polynomial *P) {
    scanf("%d", &P->degree);
    for (int i = 0; i <= P->degree; ++i) {
        scanf("%d", &P->coef[i]);
    }
}

void WritePolynomial(Polynomial P) {
    int suku_pertama = 1;
    for (int i = P.degree; i >= 0; --i) {
        int c = P.coef[i];

        if (c != 0) {
            if (suku_pertama == 0) {
                if (c > 0) {
                    printf(" + ");
                } else {
                    printf(" - ");
                }
            } else {
                if (c < 0) {
                    printf("-");
                }
            }

            if (abs(c) != 1 || i == 0) {
                printf("%d", abs(c));
            }

            if (i > 0) {
                printf("x");
                if (i > 1) {
                    printf("^%d", i);
                }
            }

            suku_pertama = 0;
        }
    }

    if (suku_pertama == 1) {
        printf("0");
    }

    printf("\n");
}

Polynomial AddPolynomial(Polynomial P1, Polynomial P2) {
    Polynomial result;
    int max_degree;
    if (P1.degree > P2.degree) {
        max_degree = P1.degree;
    } else {
        max_degree = P2.degree;
    }

    CreatePolynomial(&result, max_degree);

    for (int i = 0; i <= max_degree; ++i) {
        int a = 0;
        int b = 0;

        if (i <= P1.degree) {
            a = P1.coef[i];
        }
        if (i <= P2.degree) {
            b = P2.coef[i];
        }

        result.coef[i] = a + b;
    }

    while (max_degree > 0 && result.coef[max_degree] == 0) {
        max_degree--;
    }
    result.degree = max_degree;

    return result;
}

Polynomial MultiplyPolynomial(Polynomial P1, Polynomial P2) {
    Polynomial result;
    int total_degree = P1.degree + P2.degree;
    CreatePolynomial(&result, total_degree);

    for (int i = 0; i <= P1.degree; ++i) {
        for (int j = 0; j <= P2.degree; ++j) {
            result.coef[i + j] = result.coef[i + j] + (P1.coef[i] * P2.coef[j]);
        }
    }

    while (total_degree > 0 && result.coef[total_degree] == 0) {
        total_degree--;
    }
    result.degree = total_degree;

    return result;
}

int EvaluatePolynomial(Polynomial P, int x) {
    int result = 0;
    for (int i = P.degree; i >= 0; --i) {
        result = result * x + P.coef[i];
    }
    return result;
}

Polynomial DerivativePolynomial(Polynomial P) {
    Polynomial result;
    if (P.degree == 0) {
        CreatePolynomial(&result, 0);
        result.coef[0] = 0;
    } else {
        CreatePolynomial(&result, P.degree - 1);
        for (int i = 1; i <= P.degree; ++i) {
            result.coef[i - 1] = i * P.coef[i];
        }
    }

    return result;
}
