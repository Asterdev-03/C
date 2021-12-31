#include<stdio.h>

int bubble_sort(int A[10],int n)                        //BUBBLE SORT METHOD
{
    int num;
    printf("\nEnter no to be searched: ");
    scanf("%d",&num);

    for (int i = 0; i < n; i++)
    if(A[i] == num) 
        {
            printf("Found at %d",i+1);
            return 0;
        }
    printf("Not Found");
    return 0;
}

int linear_search(int A[10],int n)                      //LINEAR SEARCH METHOD
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n-1; j++)
            if (A[j] > A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ",A[i]);
       
    return 0;
}

void main()
{
    int A[] = {1,5,2,9,4},n = 5;

    printf("Given Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ",A[i]);

    bubble_sort(A,n);
    linear_search(A,n);
}