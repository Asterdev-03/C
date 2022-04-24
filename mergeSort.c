// Merge sort in C
#include <stdio.h>

void merge(int arr[], int beg, int mid, int end)
{
    int L[mid - beg + 1], R[end - mid];

    for (int i = 0; i < mid - beg + 1; i++)
        L[i] = arr[beg + i];
    for (int i = 0; i < end - mid; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = beg;

    while (i < mid - beg + 1 && j < end - mid)
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    while (i < mid - beg + 1)
        arr[k++] = L[i++];
    while (j < end - mid)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

int main()
{
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    printf("Sorted array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}
