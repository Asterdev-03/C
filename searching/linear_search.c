#include <stdio.h>

int linear_search(int arr[], int key)
{
    for (int i = 0; arr[i] != '\0'; i++)
        if (key == arr[i])
            return i;
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

    int index = linear_search(arr, key);
    if (index == -1)
        printf("Key not found");
    else
        printf("Key found at index %d", index);

    return 0;
}