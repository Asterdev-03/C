// To check whether a number is Even or Odd using Bitwise AND

#include <stdio.h>

void even_odd(int num) {
    // num & 1 return 1 if num is odd else 0 if even
    if ( !(num & 1) )
        printf("even");
    else
        printf("odd");
}

void main() {
    even_odd(5);
}
