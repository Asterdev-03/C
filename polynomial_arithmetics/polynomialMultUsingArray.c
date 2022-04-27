#include <stdio.h>

int main()
{
    int poly1[20], poly2[20], mult[20], deg1, deg2;

    // To read value for max degree and the operands of the first polynomial
    printf("Deg 1: ");
    scanf("%d", &deg1);
    printf("Polynomial 1:\n");
    for (int i = deg1; i >= 0; i--)
    {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly1[i]);
    }

    // To read value for max degree and the operands of the second polynomial
    printf("Deg 2: ");
    scanf("%d", &deg2);
    printf("Polnomial 2:\n");
    for (int i = deg2; i >= 0; i--)
    {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly2[i]);
    }

    // to find the highest and lowest possible degree among the polynomials
    int highest_deg = deg1 < deg2 ? deg1 : deg2;
    int lowest_deg = deg1 > deg2 ? deg1 : deg2;

    for (int coeff = 0; coeff <= deg1 + deg2; coeff++)
        mult[coeff] = 0;

    // Multiplying current term with of largest polynomial with
    // every other terms of smallest polnomial
    for (int i = highest_deg; i >= 0; i--)
        for (int j = lowest_deg; j >= 0; j--)
        {
            if (deg1 < deg2)
                mult[i + j] += poly1[i] * poly2[j];
            if (deg2 < deg1)
                mult[i + j] += poly2[i] * poly1[j];
        }

    // Display sum of the polynomials
    printf("Polnomial Multiplicative: ");
    for (int i = deg1 + deg2; i >= 0; i--)
        printf("%dx^%d + ", mult[i], i);

    return 0;
}
