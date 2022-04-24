#include <stdio.h>

#define MAXSiZE 4

int queue[MAXSiZE];
int front = -1;
int rear = -1;

void enqueue(int);
void dequeue();
void peek();
int isEmpty();
int isFull();

int main()
{
    enqueue(5);
    enqueue(16);
    dequeue();
    peek();
    enqueue(71);
    dequeue();
    peek();
    dequeue();
    peek();
    dequeue();
    enqueue(28);
    dequeue();
    peek();
    enqueue(25);

    return 0;
}

void enqueue(int item)
{
    if (isFull() == 1)
    {
        printf("Queue Overflow\n");
        return;
    }    
    if (front == -1)
        front = 0;
    queue[++rear] = item;
    printf("Enqueued %d\n", queue[rear]);
}

void dequeue()
{
    if (isEmpty() == 1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d Dequeued\n", queue[front++]);
}

void peek()
{
    if (isEmpty() == 1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Front Element: %d\n", queue[front]);
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
