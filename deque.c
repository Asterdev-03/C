#include <stdio.h>
#include <stdlib.h>

struct deque {
    int data;
    struct deque *next;
    struct deque *prev;
};