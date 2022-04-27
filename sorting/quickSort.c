#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int arr[], int first, int last)
{
    if (first < last)
    {
        int pivot = first;
        int i = first;
        int j = last;
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i < last)
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j)
                swap(&arr[i], &arr[j]);
        }
        swap(&arr[pivot], &arr[j]);
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}

int main()
{
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, size - 1);
    printf("Sorted array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}