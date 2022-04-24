#include <stdio.h>
#include <string.h>

char array[20], operators[] = {'+', '-', '*', '/', '^'};
int top, exp_size, pos;

void toPostfix(char[], char[]);
void toPrefix(char[], char[]);
int isOperator(char);
void push(char[], char[], int);
void pop(char[]);

int main()
{
    char infix_exp[20] = "", postfix_exp[20] = "", prefix_exp[20] = "";

    printf("Expression: ");
    gets(infix_exp);
    exp_size = strlen(infix_exp);

    toPostfix(infix_exp, postfix_exp);
    toPrefix(infix_exp, prefix_exp);

    printf("\nPostfix: %s", postfix_exp);
    printf("\nPrefix: %s", prefix_exp);

    return 0;
}

void toPostfix(char input_exp[], char output_exp[])
{
    pos = -1;
    top = -1;

    for (int i = 0; i < exp_size; i++)
    {
        char op = input_exp[i];
        if (isOperator(op) == -1) // checks if 'op' is an operand
            output_exp[++pos] = op;
        else
            push(input_exp, output_exp, i); // pushes the operator to stack
    }

    while (top != -1) // pops all the remaing operators in the stack
        pop(output_exp);
}

void toPrefix(char input_exp[], char output_exp[])
{
    strrev(input_exp);                // to reverse the input expression
    toPostfix(input_exp, output_exp); // to find the post fix of reversed expression
    strrev(output_exp);               // to reverse the calculated postfix expression
}

// checks whether given token is operator or not
// returns the operator precedence value if present
// else returns -1
int isOperator(char op)
{
    for (int i = 0; operators[i] != '\0'; i++)
        if (op == operators[i])
            return i;
    return -1;
}

void push(char input_exp[], char output_exp[], int index)
{
    while (isOperator(input_exp[index]) < isOperator(array[top]) && top != -1)
        pop(output_exp);

    array[++top] = input_exp[index];
}

void pop(char output_exp[])
{
    if (top != -1)
        output_exp[++pos] = array[top--];
}
