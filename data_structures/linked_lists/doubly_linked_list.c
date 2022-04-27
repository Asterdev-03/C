#include <stdio.h>
#include <stdlib.h>
/*doubly linked list has additional link in each node compared to
 *the linked list we have seen
 *a doubly linked list looks like :
 *   Node1<===>Node2<===>Node3<====>Node4<===>.....Nodek
 *whereas a singly linked list looks like:
 *   Node1--->Node2--->Node3--->Node4.......
 *The advantage of doubly linked list is that it permits traversal in both forward
 * and backward direction. Given any node you can retrieve the contents of the whole
 * list.
 */

struct dllNode
{
    // data part
    int key;

    // link part
    struct dllNode *next; // this pointer is used to store the address of the next node in the list
    struct dllNode *prev; // this pointer is used to store the address of the previous node in the list
};

typedef struct dllNode node;

// this function dynamically creates a node of dllNode type and returns its address
node *newNode()
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// this frees the memory alloted to a node and returns the chunk of memory back to the heap
void freeNode(node *remNode)
{
    free(remNode);
}

/*
 * Search Function
 */

node *searchForX(node *header, int x)
{
    if (header == NULL)
    {
        printf("%s\n", "List is empty");
        return NULL;
    }
    else
    {
        for (node *ptr = header; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->key == x)
            {
                return ptr;
            }
        }
        return NULL;
    }
}

/*Function to insert at the front (at the position of the header)
 *The new node is linked using next pointer to the present header.
 *Present header's prev pointer is set to the newnode address.
 *prev pointer of the newnode is set to NULL
 *Finally header is set to newnode.
 *
 */
void insertAtFront(node **header, int k)
{
    node *newnode;
    // check if the header is null that is, the list is empty
    if (*header == NULL)
    {
        *header = newNode();
        (*header)->key = k;
    }
    else
    {
        newnode = newNode();
        newnode->key = k;
        newnode->next = *header;
        (*header)->prev = newnode;
        *header = newnode;
    }
}

// *Insert After a given key x
// *Function inserts a new node between the node containing x
// *and its subsequent node.
// * in the function declaration note that x denotes the key after insertion
// * is done and k refers to the key inserted

void insertAfterX(node *header, int x, int k)
{
    node *xNode;
    node *kNode;
    if (header == NULL)
    {
        printf(" %s \n", "Insertion failed since list is empty");
    }
    else
    {
        xNode = searchForX(header, x);
        if (xNode == NULL)
        {
            printf("%s\n", "Insertion Failed since x not present");
        }
        else
        {
            kNode = newNode();
            kNode->key = k;
            kNode->prev = xNode;
            kNode->next = xNode->next;
            if (xNode->next != NULL)
            {
                xNode->next->prev = kNode;
            }
            xNode->next = kNode;
        }
    }
}

/*function to print the doubly linked list
 *it starts from the header and traverses forward
 *using next pointer in each node to print the key
 *
 */
void printList(node *header)
{
    if (header == NULL)
    {
        printf("\n%s\n", "The list is empty!!!");
    }
    else
    {
        printf("\n");
        for (node *ptr = header; ptr != NULL; ptr = ptr->next)
        {
            printf(" %d ", ptr->key);
        }
    }
}

/*Delete function:
 *Name of the function is : deleteX
 *It searches for the element x and deletes the node from the list.
 *
 */
//=========================================deleteX============================

void deleteX(node **header, int x)
{
    node *xNode;
    if (*header == NULL)
    {
        printf("\nDeletion failed since list is empty");
        return;
    }

    xNode = searchForX(*header, x);
    if (xNode == NULL)
    {
        printf("\nDeletion Failed since x not present");
        return;
    }

    if (xNode == *header)
        *header = xNode->next;

    if (xNode->next != NULL)
        xNode->next->prev = xNode->prev;

    if (xNode->prev != NULL)
        xNode->prev->next = xNode->next;

    freeNode(xNode);
}

//===========================================================================

int main()
{

    node *header = NULL;
    insertAtFront(&header, 10);
    insertAtFront(&header, 20);
    insertAtFront(&header, 30);
    insertAtFront(&header, 40);
    printList(header);
    insertAfterX(header, 30, 35);
    insertAfterX(header, 10, 45);
    printList(header);

    deleteX(&header, 40);
    printList(header);
    return 0;
}