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
	printf("enter coefficients and exponents of terms in polynomial:");
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
			printf("%dx^%d+", ptr->coeff, ptr->expo);
			ptr = ptr->next;
		}
		printf("%dx^%d\t+", ptr->coeff, ptr->expo);
	}
}
struct node *AddPoly()
{
	struct node *new, *P, *Q, *R, *head = NULL;
	P = Phead;
	Q = Qhead;
	while (P != NULL && Q != NULL)
	{
		if (P->expo == Q->expo)
		{
			new = (struct node *)malloc(sizeof(struct node));
			new->coeff = P->coeff + Q->coeff;
			new->expo = P->expo;
			new->next = NULL;
			P = P->next;
			Q = Q->next;
		}

		else if (P->expo > Q->expo)
		{
			new->coeff = P->coeff;
			new->expo = P->expo;
			new->next = NULL;
			P = P->next;
		}
		else
		{
			new->coeff = Q->coeff;
			new->expo = Q->expo;
			new->next = NULL;
			Q = Q->next;
		}

		if (head == NULL)
		{
			head = R = new;
		}
		else
		{
			R->next = new;
			R = new;
		}
	}

	while (P != NULL)
	{
		new = (struct node *)malloc(sizeof(struct node));
		new->coeff = P->coeff;
		new->expo = P->expo;
		new->next = NULL;

		if (head == NULL)
		{
			head = R = new;
		}
		else
		{
			R->next = new;
			R = new;
			P = P->next;
		}
	}
	while (Q != NULL)
	{
		new = (struct node *)malloc(sizeof(struct node));
		new->coeff = Q->coeff;
		new->expo = Q->expo;
		new->next = NULL;

		if (head == NULL)
		{
			head = R = new;
		}
		else
		{
			R->next = new;
			R = new;
			Q = Q->next;
		}
	}

	return (head);
}

int main()
{
	printf("enter the details of first polynomial:");
	Phead = ReadPoly();

	printf("enter the details of second polynomial:");
	Qhead = ReadPoly();

	printf("first polynomial:");
	DisplayPoly(Phead);

	printf("second polynomial:");
	DisplayPoly(Qhead);

	Rhead = AddPoly();
	printf("resultant polynomial:");
	DisplayPoly(Rhead);
}
