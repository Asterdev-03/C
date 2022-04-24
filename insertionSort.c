#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionsort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int j, temp = arr[i];
        for (j = i - 1; temp < arr[j] && j >= 0; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}

int main()
{
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionsort(arr, size);
    printf("Sorted array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}