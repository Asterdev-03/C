#include <stdio.h>

void main()
{
    int a[10],n;

    printf("Enter no of elements: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (a[j] > a[j+1])
        {
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
        
    for (int i = 0; i < n; i++)
        if (a[i]%2 != 0)
        {
            printf("%d is smallest odd number and ",a[i]);
            break;
        }
        
    for (int i = 0; i < n; i++)
        if (a[n-i-1]%2 == 0)
        {
            printf("%d is largest even number",a[n-i-1]);
            break;
        }
}