#include<stdio.h>

void main()
{
    int num, rev_num = 0,temp;

    printf("Enter number: ");
    scanf("%d",&num);

    temp = num;

    while (temp !=0)
    {
        rev_num = (rev_num * 10) + (temp % 10);
        temp /= 10;
    }
    
    printf("Reversed number: %d",rev_num);
}