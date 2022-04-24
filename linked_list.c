#include <stdio.h>
#include <stdlib.h>

struct linkedList
{
    int data;
    struct linkedList *next;
};

typedef struct linkedList node;

void printList(node *header)
{
    if (header == NULL)
    {
        printf("%s\n", "List is Empty");
        return;
    }
    for (node *ptr = header; ptr != NULL; ptr = ptr->next)
        printf("%d ", ptr->data);
    printf("\n");
}

node *searchElt(node *header, int elt)
{
    if (header == NULL)
    {
        printf("%s\n", "List is Empty");
        return NULL;
    }
    for (node *ptr = header; ptr != NULL; ptr = ptr->next)
        if (ptr->data == elt)
            return ptr;

    printf("%s\n", "Element not present");
    return NULL;
}

void insert(node **header, int data)
{
    if (*header == NULL)
    {
        *header = (node *)malloc(sizeof(node));
        (*header)->data = data;
        (*header)->next = NULL;
    }
    else
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = data;
        newNode->next = *header;
        *header = newNode;
    }
}

void insertAt(node **header, int elt, int data)
{
    node *eltNode = searchElt(*header, elt);
    if (eltNode == NULL)
        return;
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = eltNode->next;
    eltNode->next = newNode;
}

void delete (node **header)
{
    if (*header == NULL)
    {
        printf("%s\n", "List is Empty");
        return;
    }
    node *ptr = *header;
    *header = ptr->next;
    free(ptr);
}

void deleteAt(node **header, int elt)
{
    if (*header == NULL)
    {
        printf("%s\n", "List is Empty");
        return;
    }

    node *ptr;
    node *prevptr = NULL;
    for (ptr = *header; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->data == elt)
            break;
        prevptr = ptr;
    }

    if (ptr == NULL)
    {
        printf("%s\n", "Element not present");
        return;
    }

    if (ptr == *header)
        *header = (*header)->next;
    else
        prevptr->next = ptr->next;
    free(ptr);
}

void reverse(node **header) {
    node *prev = NULL, *next = NULL;
    for(node *ptr = (*header); ptr != NULL;  ptr = next) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
    }
    *header = prev;
}

void main()
{
    node *header = NULL;
    insert(&header, 20);
    printList(header);
    insert(&header, 40);
    insert(&header, 10);
    insert(&header, 15);
    insert(&header, 75);
    printList(header);

    delete (&header);
    printList(header);
    delete (&header);
    printList(header);

    insert(&header, 12);
    printList(header);

    insertAt(&header, 12, 15);
    insertAt(&header, 40, 25);
    printList(header);

    deleteAt(&header, 10);
    deleteAt(&header, 40);
    printList(header);

    reverse(&header);
    printList(header);
}