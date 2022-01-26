// Aswin K
// 12012035

#include <stdio.h>

#define MAXSiZE 3

int array[MAXSiZE];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void peek();
int isEmpty();
int isFull();

int main()
{
    int num, choice, status = 1;

    while (status == 1)
    {
        printf("1.Enqueue 2.Dequeue 3.Peek 4.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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

void enqueue()
{
    if (isFull() == 1)
    {
        printf("Overflow\n");
        return;
    }
    int item;
    printf("Enter a number: ");
    scanf("%d", &item);
    
    if (front == -1)
        front = 0;
    array[++rear] = item;
}

void dequeue()
{
    if (isEmpty() == 1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Poped: %d\n", array[front++]);
}

void peek()
{
    if (isEmpty() == 1)
    {
        printf("Underflow\n");
        return;
    }
    printf("Front Element: %d\n", array[front]);
}

int isEmpty()
{
    if (front == -1 || front > rear)
        return 1;
    return 0;
}

int isFull()
{
    if (rear == MAXSiZE - 1)
        return 1;
    return 0;
}
