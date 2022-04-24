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
    enqueue(25);
    enqueue(19);
    dequeue();
    peek();
    enqueue(71);
    enqueue(51);
    dequeue();
    dequeue();
    dequeue();
    peek();
    dequeue();
    enqueue(25);
    peek();

    return 0;
}

void enqueue(int item)
{
    if (isFull() == 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty() == 1)
    {
        front = 0;
        queue[++rear] = item;
    }
    else
    {
        rear = (rear + 1) % MAXSiZE;
        queue[rear] = item;
    }
    printf("Enqueued %d\n", queue[rear]);
}

void dequeue()
{
    if (isEmpty() == 1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d Dequeued\n", queue[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % MAXSiZE;
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
    if (front == -1 && rear == -1)
        return 1;
    return 0;
}

int isFull()
{
    if (front == (rear + 1) % MAXSiZE)
        return 1;
    return 0;
}
