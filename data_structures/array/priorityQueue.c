#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5
#define QUEUE_NUM 3

struct queue
{
    int items[10];
    int front;
    int rear;
};
typedef struct queue QUEUE;

int qempty(QUEUE *q)
{
    return (q->front > q->rear) ? 1 : 0;
}

int qfull(QUEUE *q)
{
    return (q->rear == QUEUE_SIZE - 1) ? 1 : 0;
}

void insert_rear(int item, QUEUE *q)
{
    if (qfull(q))
    {
        printf("Queue insertion not possible\n");
        return;
    }

    q->rear++;
    q->items[q->rear] = item;
}

void delete_front(QUEUE *q)
{
    int item_deleted;

    if (qempty(q))
    {
        printf("Queue is empty\nDeletion not possible\n");
        return;
    }

    item_deleted = q->items[q->front];
    q->front++;

    printf("The element deleted is:\t%d\n", item_deleted);

    if (q->front > q->rear)
    {
        q->front = 0;
        q->rear = -1;
    }
}

void display(QUEUE *q)
{
    int i;

    if (qempty(q))
    {
        printf("Queue is empty\nNo elements to display\n");
        return;
    }

    printf("The contents of queue are:\n");

    for (i = q->front; i <= q->rear; i++)
    {
        printf("%d\n", q->items[i]);
    }
}

void main()
{
    QUEUE q[QUEUE_NUM];
    int choice, item, i, priority;

    for (i = 0; i < QUEUE_NUM; i++)
    {
        q[i].front = 0;
        q[i].rear = -1;
    }

    for (;;)
    {
        printf("Enter\n");
        printf("1. Insert\n2. Delete\n");
        printf("3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter priority and item to be inserted\n");
            scanf("%d %d", &priority, &item);

            insert_rear(item, &q[priority - 1]);

            break;

        case 2:
            priority = 0;

            if (qempty(&q[0]))
            {
                printf("Queue 1 is empty\n");

                if (qempty(&q[1]))
                {
                    printf("Queue 2 is empty\n");

                    if (qempty(&q[2]))
                    {
                        printf("Queue 3 is empty\n");
                    }
                    else
                        priority = 3;
                }
                else
                    priority = 2;
            }
            else
                priority = 1;

            if (priority != 0)
            {
                printf("Deleting from queue %d\n", priority);
                delete_front(&q[priority - 1]);
            }

            break;

        case 3:
            for (i = 0; i < QUEUE_NUM; i++)
            {
                printf("Queue %d contents\n", i + 1);
                display(&q[i]);
            }

            break;

        default:
            exit(0);
        }
    }
}