#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coeff, expo;
    struct term *next;
};

typedef struct term node;

void ReadPoly(node **poly)
{
    int n;
    printf("enter total number of terms in polynomial:");
    scanf("%d", &n);
    printf("enter coefficients and exponents of terms in polynomial\n");
    for (int i = 1; i <= n; i++)
    {
        printf("enter (coeff%d,expo%d)", i, i);
        node *new = (node *)malloc(sizeof(node));
        scanf("%d", &new->coeff);
        scanf("%d", &new->expo);
        new->next = *poly;
        *poly = new;
    }
}

void DisplayPoly(node *rp)
{
    node *ptr;
    if (rp == NULL)
        printf("polynomial is Empty");
    else
    {
        ptr = rp;
        while (ptr->next != NULL)
        {
            printf("%dx^%d + ", ptr->coeff, ptr->expo);
            ptr = ptr->next;
        }
        printf("%dx^%d\t + ", ptr->coeff, ptr->expo);
    }
}

void MultPoly(node *p1, node *p2, node *rp)
{
    node *ptr1 = p1;
    node *ptr1 = p2;

    while (p1 != NULL)
    {
        while (p2 != NULL)
        {
            node *new = (node *)malloc(sizeof(node));
            new->coeff = p1->coeff * p2->coeff;
            new->expo = p1->expo + p2->coeff;
            new->next = NULL;
            if (rp == NULL)
            {
                rp = new;
                rp = rp;
            }

            else
            {
                rp->next = new;
                rp = new;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
        p2 = p2;
    }

    p1 = rp;

    while (p1 != NULL)
    {
        prev = p1;
        p2 = p1->next;
        while (p2 != NULL)
        {
            if (p1->expo == p2->expo)
            {
                p1->coeff = p1->coeff + p2->coeff;
                prev->next = p2->next;
                free(p2);
                p2 = prev->next;
            }
            else
            {
                prev = p2;
                p2 = p2->next;
            }
        }
        p1 = p1->next;
    }
}

int main()
{
    node *poly1 = NULL;
    node *poly2 = NULL;
    node *rPoly = NULL;

    printf("enter the details of first polynomial\n");
    ReadPoly(&poly1);

    printf("enter the details of second polynomial\n");
    ReadPoly(&poly2);

    printf("first polynomial:");
    DisplayPoly(poly1);

    printf("second polynomial:");
    DisplayPoly(poly2);

    MultPoly(poly1, poly2, rPoly);
    printf("resultant polynomial:");
    DisplayPoly(rPoly);
}