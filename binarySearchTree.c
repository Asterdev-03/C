#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

typedef struct treeNode node;

void insertNode(node **root, int key)
{
    if ((*root) == NULL)
    {
        *root = (node *)malloc(sizeof(node));
        (*root)->data = key;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else
    {
        if (key < (*root)->data)
            insertNode(&((*root)->left), key);
        else
            insertNode(&((*root)->right), key);
    }
}

void printInOrder(node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

void printPreOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(node *root)
{
    if (root != NULL)
    {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ", root->data);
    }
}

node *search(node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    else if (key < (root->data))
        return search(root->left, key);
    else
        return search(root->right, key);
}

node *searchNode(node *root, int key, node **parent)
{
    if (root == NULL)
        return NULL;
    if (key < (root->data))
    {
        (*parent) = root;
        return searchNode(root->left, key, &(*parent));
    }
    else if (key > (root->data))
    {
        (*parent) = root;
        return searchNode(root->right, key, &(*parent));
    }
    else
        return root;
    return NULL;
}

void deleteNode(node **root, int key)
{
    if ((*root) == NULL)
    {
        printf("Tree is Empty\n");
        return;
    }

    node *parent = NULL;
    node *targetNode = searchNode((*root), key, &parent);

    if (targetNode == NULL)
    {
        printf("Element Not Found\n");
        return;
    }
    // if target node has only one child that is on the right
    if (targetNode->left == NULL)
    {

        if (parent != NULL)
            if (parent->left == targetNode)
                parent->left = targetNode->right;
            else
                parent->right = targetNode->right;
        else
            *root = targetNode->right;
    }
    // if target node has only one child that is on the left
    else if (targetNode->right == NULL)
    {
        if (parent != NULL)
            if (parent->left == targetNode)
                parent->left = targetNode->left;
            else
                parent->right = targetNode->left;
        else
            *root = targetNode->left;
    }
    // if target node has two children
    else
    {

        node *ptr, *parentOfSuccessor = targetNode;
        for (ptr = targetNode->left; ptr->right != NULL; ptr = ptr->right)
            parentOfSuccessor = ptr;

        if (parent == NULL)
        {
            if (parentOfSuccessor == targetNode)
            {
                ptr->right = (*root)->right;
                (*root) = ptr;
            }
            else
            {

                targetNode->data = ptr->data;
                parentOfSuccessor->right = NULL;
            }
            free(ptr);
            return;
        }
        if (parentOfSuccessor == targetNode)
        {
            if (parent->left == targetNode)
                parent->left = ptr;
            else
                parent->right = ptr;
            ptr->right = targetNode->right;
        }
        else
        {
            parentOfSuccessor->right = ptr->left;
            ptr->left = targetNode->left;
            ptr->right = targetNode->right;
        }
    }
    free(targetNode);
}

int countLeafs(node *root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    else
       return countLeafs(root->left) + countLeafs(root->right);
}

int main()
{
    node *root = NULL;

    /*
                            15
                 7                   21
            6        9          _           35
        5     _   8    10               32      40

    */

    insertNode(&root, 15);
    insertNode(&root, 7);
    insertNode(&root, 21);
    insertNode(&root, 6);
    insertNode(&root, 9);
    insertNode(&root, 35);
    /*
    insertNode(&root, 5);
    insertNode(&root, 8);
    insertNode(&root, 10);
    insertNode(&root, 32);
    insertNode(&root, 40);
*/
    printf("\nInorder : ");
    printInOrder(root);
    printf("\nPreorder : ");
    printPreOrder(root);
    printf("\nPostorder : ");
    printPostOrder(root);

    node *ptr = search(root, 35);
    if (ptr == NULL)
        printf("Element Not Found");
    else
        printf("\n%d is Found", ptr->data);

    deleteNode(&root, 35);

    printf("\nCurrent Order : ");
    printInOrder(root);

    printf("\nLeafs : %d", countLeafs(root));

    return 0;
}