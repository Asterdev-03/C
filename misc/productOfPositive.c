#include <stdio.h>

int main()
{
    int status = 1, product = 1;
    while (status == 1)
    {
        int num;
        printf("Enter a number : ");
        scanf("%d", &num);
        if (num < 0)
            status = 0;
        else
            product *= num;
    }
    printf("Product is : %d", product);
}