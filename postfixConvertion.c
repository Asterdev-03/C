#include <stdio.h>
#include <string.h>

struct stack
{
    char array[20];
    int top;
} opstk;

void push(char *input_exp, char *output_exp, int *exp_pos, int index) {
    if (input_exp[index] == '+' || input_exp[index] == '-') 
        while (opstk.array[opstk.top] != '+' && opstk.array[opstk.top] != '-' && opstk.top != -1)
            pop(output_exp, & *exp_pos);

    else if (input_exp[index] == '*' || input_exp[index] == '/') 
        while (opstk.array[opstk.top] == '^' && opstk.top != -1)
            pop(output_exp, & *exp_pos);
        
    opstk.array[++opstk.top] = input_exp[index];
}

void pop(char *exp, int *exp_pos) {
    if(opstk.top != -1)
        exp[++ *exp_pos] = opstk.array[opstk.top--];
}

int main() {
    char exp[20];
    int exp_size;

    printf("Expression: ");
    gets(exp);

    postfixConvertion(exp);
    prefixConvertion(exp);
    
    return 0;
}

void postfixConvertion(char exp[]) {
    int exp_size = strlen(exp), exp_pos = -1;
    char postfix_exp[20] = "";
    opstk.top = -1;

    for (int i = 0; i < exp_size; i++)
            if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= '0' && exp[i] <= '9')
                postfix_exp[++exp_pos] = exp[i];
            else 
                push(exp, postfix_exp, &exp_pos, i);
    
    while (opstk.top >= 0)
            pop(postfix_exp, &exp_pos);
    
    printf("\nPostfix: %s", postfix_exp);

    return postfix_exp;
}

void prefixConvertion(char exp[]) {
    char prefix_exp[20] = "";
    int exp_size = strlen(exp), exp_pos = -1;
    opstk.top = -1;

    strrev(exp);

    for (int i = 0; i < exp_size; i++)
            if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= '0' && exp[i] <= '9')
                prefix_exp[++exp_pos] = exp[i];
            else 
                push(exp, prefix_exp, &exp_pos, i);
    
    while (opstk.top >= 0)
            pop(prefix_exp, &exp_pos);    

    strrev(prefix_exp);

    printf("\nPrefix: %s", prefix_exp);
}

