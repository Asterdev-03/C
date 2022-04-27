#include <stdio.h>

void sort_array(int arr[])
{
    for (int i = 1; arr[i] != '\0'; i++)
    {
        int j, temp = arr[i];
        for (j = i - 1; temp < arr[j] && j >= 0; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}

int binary_search(int arr[], int start, int end, int key)
{
    if (end >= start)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            return binary_search(arr, start, mid - 1, key);
        return binary_search(arr, mid + 1, end, key);
        ;
    }
    return -1;
}

int main()
{
    int arr[50], size, key;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to be searched in the array: ");
    scanf("%d", &key);

    sort_array(arr);
    int index = binary_search(arr, 0, size, key);

    if (index == -1)
        printf("Key not found");
    else
        printf("Key found at index %d", index);

    return 0;
}