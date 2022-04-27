/**
 * @file circularQueue.c
 * @brief Implementation of a Circular Queue using array in C.
 * @details The implementation has following functionalities:
 *  - Enqueue
 *  - Dequeue
 *  - Peek, gives the element at front index of queue
 */

#include <stdio.h>

// Initialization
#define MAXSiZE 4
int queue[MAXSiZE];
int front = -1;
int rear = -1;

void enqueue(int);
void dequeue();
void peek();
int isEmpty();
int isFull();

/**
 * @brief Inserts item to rear index of queue
 * @param item the value that is enqueued
 */
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
        // if queue is not full and rear + 1 reaches max size of array, then
        // circle back to index 0 and store the element here using this formula
        rear = (rear + 1) % MAXSiZE;
        queue[rear] = item;
    }
    printf("Enqueued %d\n", queue[rear]);
}

/**
 * @brief Deletes item on front index from queue
 */
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
    {
        // if queue is not empty and front + 1 reaches max size of array, then
        // circle back to index 0 and delete the element here using this formula
        front = (front + 1) % MAXSiZE;
    }
}

/**
 * @brief Displays the element on front index of queue
 */
void peek()
{
    if (isEmpty() == 1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Front Element: %d\n", queue[front]);
}

/**
 * @brief Checks whether queue is empty or not
 * @return int 1 if queue is empty and 0 if not
 */
int isEmpty()
{
    return (front == -1 && rear == -1);
}

/**
 * @brief Checks whether queue is full or not
 * @return int 1 if queue is full and 0 if not
 */
int isFull()
{
    return (front == (rear + 1) % MAXSiZE);
}

int main()
{
    int status = 1, option, key;
    while (status == 1)
    {
        printf("1. Enqueue 2. Dequeue 3. Peek 4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &key);
            enqueue(key);
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
            printf("Enter appropriate option.\n");
            break;
        }
    }
    return 0;
}