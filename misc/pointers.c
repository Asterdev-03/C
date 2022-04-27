#include<stdio.h>

void fun(int *address,int n)
{
    for (int i = 0; i < n/2; i++)
    {
        int temp = *address;
        *address = *(address + n - i - 1);
        *(address + n - i - 1) = temp;
    }
}

void main()
{
    int A[] = {1,2,3} , num = 3;
    fun(&A,num);
    for (int i = 0; i < num; i++)
        printf("%d",A[i]);
    
}