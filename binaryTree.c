#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void insert(struct Node **, int );
void preOrder(struct Node *);
void inOrder(struct Node *);
void postOrder(struct Node *);


int main()
{
    struct Node *root= 0;
    int num, opt= 1;
    do
    {
        printf("Enter the element:\n");
        scanf("%d", & num);
        insert(&root, num);
        printf("To continue Enter 1, else Enter 0: ");
        scanf("%d", & opt);
    } 
    while (opt == 1);

    printf("Preorder: ");
    preOrder(root);
    printf("\nInorder: ");
    inOrder(root);
    printf("\nPostorder: ");
    postOrder(root);
}

void insert(struct Node **rt, int x)
{
   if(*rt == NULL)
   {
       *rt = (struct Node *)malloc(sizeof(struct Node));
       (*rt)->data= x;
       (*rt)->left= 0;
       (*rt)->right= 0;
   }
   else {
        if(x < (*rt)->data)
            insert(&((*rt)->left), x);
        else
            insert(&((*rt)->right), x);
   }
}

void preOrder(struct Node *rt)
{
    if (rt != 0)
    {
        printf("%d  ", rt->data);
        preOrder(rt->left);
        preOrder(rt->right);
    }
}

void inOrder(struct Node *rt)
{
    if (rt != 0)
    {
        inOrder(rt->left);
        printf("%d  ", rt->data);
        inOrder(rt->right);
    }
}

void postOrder(struct Node *rt)
{
    if (rt != 0)
    {
        postOrder(rt->left);
        postOrder(rt->right);
        printf("%d  ", rt->data);
    }
}