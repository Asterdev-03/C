/**
 * @file infixToPostfix.c
 * @brief Expression conversion in C.
 * @details To convert an infixed expression to postfixed expression
 */

#include <stdio.h>
#include <ctype.h>

// Globally declared array Stack representing the stack, and
// a variable top pointing to top most index of the array
char Stack[50];
int top = -1;

void push(char);
char pop();
int getPriority(char);
void toPostfix(char[], char[]);

/**
 * @brief Push Operation
 * @param x element that is pushed into stack
 */
void push(char x)
{
    Stack[++top] = x;
}

/**
 * @brief Pop Operation
 * @return char element that is poped from stack
 */
char pop()
{
    if (top == -1)
        return -1;
    else
        return Stack[top--];
}

/**
 * @brief Get the priority of the operators
 * @param x operator whose priority is returned
 * @return int priority value
 */
int getPriority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

/**
 * @brief Conversion procedure, infix to postfix
 * @param infix expression in infix form
 * @param postfix expression in postfix form
 */
void toPostfix(char infix[], char postfix[])
{
    // pos represents top most index value of postfix array
    int pos = -1;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        // checks if it is an operand
        if (isalnum(infix[i]))
            postfix[++pos] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')')
        {
            char x = pop();
            // pops all the remaing elements in stack untill it reaches '('
            while (x != '(')
                postfix[++pos] = x;
        }
        else
        {
            // pushes the operator into stack after poping all greater precedence elements in stack
            while (getPriority(Stack[top]) >= getPriority(infix[i]))
                postfix[++pos] = pop();
            push(infix[i]);
        }
    }
    // pops all the remaining operators in the stack
    while (top != -1)
    {
        postfix[++pos] = pop();
    }
}

int main()
{
    char infix[20], postfix[20];
    printf("Enter the Infix expression: ");
    scanf("%s", &infix);

    toPostfix(infix, postfix);

    printf("Postfix expression: %s", postfix);
    return 0;
}