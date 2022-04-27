# include <stdio.h>

int main() {
    int poly1[20], poly2[20], sum[20], deg1, deg2;

    // To read value for max degree and the operands of the first polynomial
    printf("Deg 1: ");
    scanf("%d", &deg1);
    printf("Polynomial 1:\n");
    for (int i = deg1; i >= 0; i-- ) {
        printf("Coefficient of x^%d: ",i);
        scanf("%d", &poly1[i]);
    }

    // To read value for max degree and the operands of the second polynomial
    printf("Deg 2: ");
    scanf("%d", &deg2);
    printf("Polnomial 2:\n");
    for (int i = deg2; i >= 0; i-- ) {
    printf("Coefficient of x^%d: ",i);
        scanf("%d", &poly2[i]);
    }

    // to find the highest and lowest possible degree among the plynomials
    int largestPolyDeg = deg1 > deg2 ? deg1 : deg2;
    int smallestPolyDeg = deg1 < deg2 ? deg1 : deg2;

    // stores values of the sum of the operands
    // with same coefficients upto the lowest degree
    for (int i = 0; i <= smallestPolyDeg; i++)
        sum[i] = poly1[i] + poly2[i];

    // stores values of remaining operands to sum
        if(deg1 > deg2)
            for (int i = smallestPolyDeg + 1; i <= largestPolyDeg; i++) 
                sum[i] = poly1[i];
        if(deg2 > deg1)
            for (int i = smallestPolyDeg + 1; i <= largestPolyDeg; i++) 
                sum[i] = poly2[i];
    
    // Display sum of the polynomials
    printf("Polnomial Sum: ");
    for (int i = largestPolyDeg; i >= 0; i--)
        printf("%dx^%d + ",sum[i], i);
    return 0;
}
