#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff, expo;
    struct node *next;
};
struct node *Phead, *Qhead, *Rhead;

struct node *ReadPoly()
{
    struct node *new, *ptr, *head = NULL;
    int n, i;
    printf("enter total number of terms in polynomial:");
    scanf("%d", &n);
    printf("enter coefficients and exponents of terms in polynomial\n");
    for (i = 1; i <= n; i++)
    {
        printf("enter (coeff%d,expo%d)", i, i);
        new = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &new->coeff);
        scanf("%d", &new->expo);
        new->next = NULL;
        if (head == NULL)
        {
            head = new;
            ptr = head;
        }
        else
        {
            ptr->next = new;
            ptr = new;
        }
    }
    return (head);
}
void DisplayPoly(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
        printf("polynomial is Empty");
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            printf("%dx^%d + ", ptr->coeff, ptr->expo);
            ptr = ptr->next;
        }
        printf("%dx^%d\t + ", ptr->coeff, ptr->expo);
    }
}

struct node *MultPoly()
{
    struct node *new, *P, *Q, *R, *prev, *head = NULL;
    P = Phead;
    Q = Qhead;
    while (P != NULL)
    {
        while (Q != NULL)
        {
            new = (struct node *)malloc(sizeof(struct node));
            new->coeff = P->coeff * Q->coeff;
            new->expo = P->expo + Q->coeff;
            new->next = NULL;
            if (head == NULL)
            {
                head = new;
                R = head;
            }

            else
            {
                R->next = new;
                R = new;
            }
            Q = Q->next;
        }
        P = P->next;
        Q = Qhead;
    }

    P = head;

    while (P != NULL)
    {
        prev = P;
        Q = P->next;
        while (Q != NULL)
        {
            if (P->expo == Q->expo)
            {
                P->coeff = P->coeff + Q->coeff;
                prev->next = Q->next;
                free(Q);
                Q = prev->next;
            }
            else
            {
                prev = Q;
                Q = Q->next;
            }
        }
        P = P->next;
    }
    return (head);
}

int main()
{
    printf("enter the details of first polynomial\n");
    Phead = ReadPoly();

    printf("enter the details of second polynomial\n");
    Qhead = ReadPoly();

    printf("first polynomial:");
    DisplayPoly(Phead);

    printf("second polynomial:");
    DisplayPoly(Qhead);

    Rhead = MultPoly();
    printf("resultant polynomial:");
    DisplayPoly(Rhead);
}