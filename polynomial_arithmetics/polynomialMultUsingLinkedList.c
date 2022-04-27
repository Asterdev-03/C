#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coeff, expo;
    struct term *next;
};

typedef struct term node;

void displayPoly(node *header)
{
    if (header == NULL)
    {
        printf("%s\n", "List is Empty");
        return;
    }
    node *ptr = header;
    while (ptr->next != NULL)
    {
        printf("%dx^%d + ", ptr->coeff, ptr->expo);
        ptr = ptr->next;
    }
    printf("%dx^%d\n", ptr->coeff, ptr->expo);
}

void readPoly(node **header, int coeff, int expo)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->coeff = coeff;
    newNode->expo = expo;

    if (*header == NULL)
    {
        newNode->next = NULL;
        *header = newNode;
    }
    else if (expo >= (*header)->expo)
    {
        newNode->next = (*header);
        *header = newNode;
    }
    else
    {
        node *prev = (*header);
        for (node *ptr = (*header)->next; ptr != NULL; ptr = ptr->next)
        {
            if (expo >= ptr->expo)
                break;
            prev = ptr;
        }
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

void polynomialMult(node *poly1, node *poly2, node **poly3)
{
    node *ptr1 = poly1, *ptr2 = poly2, *ptr3;

    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            node *new = (node *)malloc(sizeof(node));
            new->coeff = ptr1->coeff + ptr2->coeff;
            new->expo = ptr1->expo;
            new->next = NULL;
            
            if ((*poly3) == NULL)
            {
                (*poly3) = new;
                ptr3 = new;
            }
            else
            {
                ptr3->next = new;
                ptr3 = new;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
        
    ptr1 = (*poly3);
    while (ptr1 != NULL)
    {
        
    }
    
        if (ptr1->expo == ptr2->expo)
        {
            

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            new->coeff = ptr1->coeff;
            new->expo = ptr1->expo;
            new->next = NULL;

            ptr1 = ptr1->next;
        }
        else
        {
            new->coeff = ptr2->coeff;
            new->expo = ptr2->expo;
            new->next = NULL;

            ptr2 = ptr2->next;
        }

        if ((*poly3) == NULL)
        {
            (*poly3) = new;
            ptr3 = new;
        }
        else
        {
            ptr3->next = new;
            ptr3 = new;
        }
    }

    while (ptr1 != NULL)
    {
        node *new = (node *)malloc(sizeof(node));
        new->coeff = ptr1->coeff;
        new->expo = ptr1->expo;

        if ((*poly3) == NULL)
        {
            (*poly3) = new;
            ptr3 = new;
        }
        else
        {
            ptr3->next = new;
            ptr3 = new;
            ptr1 = ptr1->next;
        }
    }
    while (ptr2 != NULL)
    {
        node *new = (node *)malloc(sizeof(node));
        new->coeff = ptr2->coeff;
        new->expo = ptr2->expo;

        if ((*poly3) == NULL)
        {
            (*poly3) = new;
            ptr3 = new;
        }
        else
        {
            ptr3->next = new;
            ptr3 = new;
            ptr2 = ptr2->next;
        }
    }
}

void main()
{
    node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    readPoly(&poly1, 20, 3);
    readPoly(&poly1, 5, 4);
    readPoly(&poly1, 10, 1);
    readPoly(&poly1, 17, 2);
    displayPoly(poly1);

    readPoly(&poly2, 10, 5);
    readPoly(&poly2, 15, 3);
    readPoly(&poly2, 7, 4);
    readPoly(&poly2, 9, 1);
    displayPoly(poly2);

    polynomialMult(poly1, poly2, &poly3);
    displayPoly(poly3);
}