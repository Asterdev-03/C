#include <stdio.h>


void even_odd(int num)
{
    if ( !(num & 1) )
        printf("even");
    else
        printf("odd");
}

void main()
{
    even_odd(5);
}
