/**
 * @file stack.c
 * @brief Implementation of a Stack using array in C.
 * @details The implementation has following functionalities:
 *  - Push
 *  - Pop
 *  - Peek, gives the element at top index of stack
 */

#include <stdio.h>

// Initialization
#define MAXSiZE 4
int stack[MAXSiZE];
int top = -1;

void push(int);
void pop();
void peek();
int isEmpty();
int isFull();

/**
 * @brief Inserts item to top index of stack
 * @param item the value that is pushed
 */
void push(int item)
{
    if (isFull() == 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
    printf("Pushed: %d\n", stack[top]);
}

/**
 * @brief Deletes item on top index from stack
 */
void pop()
{
    if (isEmpty() == 1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Poped: %d\n", stack[top--]);
}

/**
 * @brief Displays the element on top index of stack
 */
void peek()
{
    if (isEmpty() == 1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Top Element: %d\n", stack[top]);
}

/**
 * @brief Checks whether stack is empty or not
 * @return int 1 if stack is empty and 0 if not
 */
int isEmpty()
{
    return (top == -1);
}

/**
 * @brief Checks whether stack is full or not
 * @return int 1 if stack is full and 0 if not
 */
int isFull()
{
    return (top == MAXSiZE - 1);
}

int main()
{
    int status = 1, option, key;
    while (status == 1)
    {
        printf("1. Push 2. Pop 3. Peek 4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &key);
            push(key);
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
            printf("Enter appropriate option.\n");
            break;
        }
    }
    return 0;
}