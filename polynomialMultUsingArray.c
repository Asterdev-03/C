# include <stdio.h>

int main() {
    int poly1[20], poly2[20], mult[20], deg1, deg2;

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
    
    for (int coeff = 0; coeff < deg1 + deg2 -1; coeff++)
        mult[coeff] = 0;
    
    // Multiplying current term with of largest polynomial with
    // every other terms of smallest polnomial
    for (int i = 0; i < highest_deg; i++)
        for (int j = 0; j < lowest_deg; j++) {
            if (deg1 < deg2)
                mult[i + j] += poly1[i] * poly2[j];
            if (deg2 < deg1)
                mult[i + j] += poly2[i] * poly1[j]; 
        }

    // Display sum of the polynomials
    printf("Polnomial Sum: ");
    for (int coeff = 0; coeff < deg1 + deg2 -1; coeff++)
        printf("%d ", mult[coeff]);

    return 0;
}
