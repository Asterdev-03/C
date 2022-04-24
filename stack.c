#include <stdio.h>

#define MAXSiZE 3

int stack[MAXSiZE];
int top = -1;

void push(int);
void pop();
void peek();
int isEmpty();
int isFull();

int main()
{
    push(5);
    push(16);
    push(28);
    push(71);
    peek();
    pop();
    peek();
    pop();
    peek();
    pop();
    pop();
    push(46);
    peek();

    return 0;
}

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

void pop()
{
    if (isEmpty() == 1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Poped: %d\n", stack[top--]);
}

void peek()
{
    if (isEmpty() == 1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Top Element: %d\n", stack[top]);
}

int isEmpty()
{
    return (top == -1);
}

int isFull()
{
    return (top == MAXSiZE - 1);
}
