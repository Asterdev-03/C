/**
 * @file linked_list.c
 * @brief Implementation of a Linked List in C
 * @details The implementation has following functionalities:
 *  - Create a new Node
 *  - Insertion of node at beginning or at specific key in list
 *  - Deletion of node at beginning or at specific key in list
 *  - Reversing a linked list
 *  - Searching for a node having specific key
 *  - Printing the linked list
 */

#include <stdio.h>
#include <stdlib.h>

// Basic structure of a node in a linked list 
typedef struct linkedList
{
    int data;
    struct linkedList *next;
} node;

node *newNode(int );
void purge(node **);
void insert(node **, int);
void insertAt(node **, int, int);
void delete (node **);
void deleteAt(node **, int);
void printList(node *);
node *searchElt(node *, int);
void reverse(node **);

/**
 * @brief  The function to create a node and initialize it's data and link parts
 * 
 * @param data the data part to be stored in the node
 * @return node* new node with provided data
 * @note the node must be deleted before program terminates to avoid memory leaks
 */
node *newNode(int data)
{
    // creates a node
    node *new = (node *)malloc(sizeof(node));

    // initializes the node
    new->data = data;
    new->next = NULL;

    return new;
}

/**
 * @brief Utilary procedure, to free all the nodes in the list
 * @param header the pointer to the head node
 */
void purge(node **header)
{
    if (*header != NULL)
    {
        if ((*header)->next != NULL)
            purge(&(*header)->next);
        free(*header);
        *header = NULL;
    }
}

/**
 * @brief Prints all the data stored in the list
 * @param header the pointer to head node
 */
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

/**
 * @brief Search procedure,to traverse through the list to find the input key
 * @param header the pointer to head node
 * @param elt he input key, that is to be searched in the list
 * @return node* if key present or NULL if key not in list
 */
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

/**
 * @brief Insertion procedure, which inserts input key into the list
 * @param header the pointer to head node
 * @param data the input key value, that is to be stored in the list
 */
void insert(node **header, int data)
{
    if (*header == NULL)
    {
        *header = newNode(data);
    }
    else
    {
        node *new = newNode(data);
        new->next = *header;
        *header = new;
    }
}

/**
 * @brief Insertion procedure, searches the target element in the list and then
 * inserts input key after that element, if present
 * @param header the pointer to head node
 * @param elt  the target element
 * @param data the input key value, that is to be stored in the list
 */
void insertAt(node **header, int elt, int data)
{
    node *eltNode = searchElt(*header, elt);
    if (eltNode == NULL)
        return;
    node *new = newNode(data);
    new->next = eltNode->next;
    eltNode->next = new;
}

/**
 * @brief  Deletion procedure, removes the head node in the list
 * @param header the pointer to head node
 */
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

/**
 * @brief Deletion procedure, searches the target element in the tree and then
 * removes that element, if present
 * @param header the pointer to head node
 * @param elt the target element
 */
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

/**
 * @brief Reverse the elements in the linked list
 * @param header the pointer to head node
 */
void reverse(node **header)
{
    node *prev = NULL, *next = NULL;
    for (node *ptr = (*header); ptr != NULL; ptr = next)
    {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
    }
    *header = prev;
}

int main()
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
    
    purge(&header);
    return 0;
}