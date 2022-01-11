# include <stdio.h>

int main() {
    int poly1[20], poly2[20], sum[20], deg1, deg2;

    // To read value for max degree and the operands of the first polynomial
    printf("Deg 1: ");
    scanf("%d", &deg1);
    printf("Polnomial 1: ");
    for (int coeff = 0; coeff<deg1; coeff++)
        scanf("%d", &poly1[coeff]);

    // To read value for max degree and the operands of the second polynomial
    printf("Deg 2: ");
    scanf("%d", &deg2);
    printf("Polnomial 2: ");
    for (int coeff = 0; coeff<deg2; coeff++)
        scanf("%d", &poly2[coeff]);

    // to find the highest and lowest possible degree among the plynomials
    int highest_deg = deg1 < deg2 ? deg1 : deg2;
    int lowest_deg = deg1 > deg2 ? deg1 : deg2;

    // stores values of the sum of the operands
    // with same coefficients upto the lowest degree
    for (int coeff = 0; coeff < lowest_deg; coeff++)
        sum[coeff] = poly1[coeff] + poly2[coeff];

    // stores values of remaining operands to sum
    for (int coeff = lowest_deg; coeff < highest_deg; coeff++) {
        if(deg1 > deg2)
            sum[coeff] = poly1[coeff];
        if(deg2 > deg1)
            sum[coeff] = poly2[coeff];
    }
    
    // Display sum of the polynomials
    printf("Polnomial Sum: ");
    for (int coeff = 0; coeff < highest_deg; coeff++)
        printf("%d ", sum[coeff]);

    return 0;
}
