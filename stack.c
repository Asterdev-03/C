// Aswin K
// 12012035

#include <stdio.h>

#define MAXSiZE 3

int array[MAXSiZE];
int top = -1;

void push();
void pop();
void peek();
int isEmpty();
int isFull();

int main()
{
    int choice, status = 1;

    while (status == 1)
    {
        printf("1.Push 2.Pop 3.Peek 4.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            status = 0;
            break;
        default:
            status = 0;
            break;
        }
    }
    return 0;
}

void push()
{
    if (isFull() == 1)
    {
        printf("Overflow\n");
        return;
    }
    int item;
    printf("Enter a number: ");
    scanf("%d", &item);
    array[++top] = item;
    printf("Pushed: %d\n", array[top]);
}

void pop()
{
    if (isEmpty() == 1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Poped: %d\n", array[top--]);
}

void peek()
{
    if (isEmpty() == 1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Top Element: %d\n", array[top]);
}

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == MAXSiZE - 1);
}
