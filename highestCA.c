#include <stdio.h>

float high(float CA1, float CA2, float CA3)
{
    if (CA1 > CA2 && CA1 > CA3)
        return CA1;
    if (CA2 > CA1 && CA2 > CA3)
        return CA2;
    return CA3;
}

int main()
{
    float ca1, ca2, ca3, highest;

    printf("Enter the marks got in INT102\n");
    printf("Marks in CA 1: ");
    scanf("%f", &ca1);
    printf("Marks in CA 2: ");
    scanf("%f", &ca2);
    printf("Marks in CA 3: ");
    scanf("%f", &ca3);

    highest = high(ca1, ca2, ca3);

    printf("Highest Score is : %f", highest);
}