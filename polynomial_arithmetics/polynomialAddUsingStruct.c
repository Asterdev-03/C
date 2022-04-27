# include <stdio.h>

struct polynomial{
    int coeff;
    int expo;
} p1[20], p2[20], sum[20];

int main() {
    int terms1, terms2, terms3=0;

    // To read value for no of terms and the terms of the first polynomial
    printf("Terms 1: ");
    scanf("%d", &terms1);
    printf("Polnomial 1: ");
    for (int i = 0; i < terms1; i++) {
        scanf("%d", &p1[i].coeff);
        scanf("%d", &p1[i].expo);
    }

    // To read value for no of terms and the terms of the second polynomial
    printf("Terms 2: ");
    scanf("%d", &terms2);
    printf("Polnomial 2: ");
    for (int i = 0; i < terms2; i++) {
        scanf("%d", &p2[i].coeff);
        scanf("%d", &p2[i].expo);
    }

    // stores values of the sum of the coefficients
    // with same exponent upto the lowest degree
    int i=0, j=0;
    while (i<terms1 && j<terms2) 
        if (p1[i].expo == p2[j].expo)
        {
            sum[terms3].coeff = p1[i].coeff + p2[j].coeff;
            sum[terms3].expo = p1[i].expo;
            i++;
            j++;
            terms3++;
        }
        else if (p1[i].expo > p2[j].expo)
        {
            sum[terms3].coeff = p1[i].coeff;
            sum[terms3].expo = p1[i].expo;
            i++;
            terms3++;
        }
        else {
            sum[terms3].coeff = p2[j].coeff;
            sum[terms3].expo = p2[j].expo;
            j++;
            terms3++;
        }
        
    // stores values of remaining terms to sum
    while (i < terms1)
    {
        sum[terms3].coeff = p1[i].coeff;
        sum[terms3].expo = p1[i].expo;
        i++;
        terms3++;
    }
    while (i < terms2)
    {
        sum[terms3].coeff = p2[j].coeff;
        sum[terms3].expo = p2[j].expo;
        j++;
        terms3++;
    }
    
    // Display sum of the polynomials
    printf("Polnomial Sum: ");
    for (int i = 0; i < terms3; i++)
        printf("%d x^%d + ", sum[i].coeff, sum[i].expo);

    return 0;
}
