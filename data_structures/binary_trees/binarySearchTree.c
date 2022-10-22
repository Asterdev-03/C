/**
 * @file binarySearchTree.c
 * @brief Implementation of Binary Search Tree in C.
 * @details The implementation has following functionalities:
 *  - Insertion
 *  - Deletion
 *  - Searching using a key value
 *  - Traversal of nodes in post, pre and in order of values (from left to right)
 */

#include <stdio.h>
#include <stdlib.h>

// Basic structure of a node in a tree
typedef struct treeNode
{
    int data;               // data part of node
    struct treeNode *left;  // left child
    struct treeNode *right; // right child
} node;

node *newNode(int data);
void purge(node **root);
void insertNode(node **root, int key);
void printInOrder(node *root);
void printPreOrder(node *root);
void printPostOrder(node *root);
node *search(node *root, int key);
node *getSuccessorNode(node *root);
node *deleteNode(node **root, int key);
int countLeafs(node *root);

/**
 * @brief The function to create a node and initialize it's data and link parts
 * @param data the data part to be stored in the node
 * @returns new node with provided data
 * @note the node must be deleted before program terminates to avoid memory leaks
 */
node *newNode(int data)
{
    // creates a node
    node *new = (node *)malloc(sizeof(node));

    // initializes the node
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    return new;
}

/**
 * @brief Utilary procedure, to free all the nodes in the tree
 * @param root the pointer to the parent node
 */
void purge(node **root)
{
    if (*root != NULL)
    {
        if ((*root)->left != NULL)
            purge(&(*root)->right);
        if ((*root)->right != NULL)
            purge(&(*root)->left);
        free(*root);
        *root = NULL;
    }
}

/**
 * @brief Insertion procedure, which inserts input key into the tree
 * @param root the pointer to the parent node
 * @param key the input key value, that is to be stored in new node
 */
void insertNode(node **root, int key)
{
    // if root of subtree is null, insert key in root,
    // if key is lesser than root key, insert in left leaf, and
    // if key is greater than root key, insert in right leaf
    if ((*root) == NULL)
        *root = newNode(key);
    else if (key < (*root)->data)
        insertNode(&((*root)->left), key);
    else
        insertNode(&((*root)->right), key);
}

/**
 * @brief Traversal procedure, to list the current keys in the tree in order of value
 * @param root the pointer to parent node
 */
void printInOrder(node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

/**
 * @brief Traversal procedure, to list the current keys in the tree in pre order of value
 * @param root the pointer to parent node
 */
void printPreOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

/**
 * @brief Traversal procedure, to list the current keys in the tree in post order of value
 * @param root the pointer to parent node
 */
void printPostOrder(node *root)
{
    if (root != NULL)
    {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("%d ", root->data);
    }
}

/**
 * @brief Search procedure,to traverse through the tree to find the input key
 * @param root the pointer to parent node
 * @param key the input key, that is to be searched in the tree
 * @return node* if key present or NULL if key not in tree
 */
node *search(node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    else if (key < (root->data))
        return search(root->left, key);
    else
        return search(root->right, key);
}

/**
 * @brief Get the Successor Node object
 * @details To find the greatest key in the left subtree by
 * traversing to the rightmost node in the left branch
 * @param root the pointer to parent node
 * @return node* successor node having max value
 */
node *getSuccessorNode(node *root)
{
    // if there is no leaf to the right, then this is
    // the node having the maximum key value
    if (root->right != NULL)
        return getSuccessorNode(root->right);
    return root;
}

/**
 * @brief Deletion procedure, searches the input key in the tree and then
 * removes that node if present
 * @param root the pointer to parent node
 * @param key the input value that is searched in the tree and removed
 * @return node* pointer to parent node
 */
node *deleteNode(node **root, int key)
{
    // search for the node having input key in the tree
    // if not found, return null
    if (*root == NULL)
        return *root;
    else if (key > (*root)->data)
        (*root)->right = deleteNode(&(*root)->right, key);
    else if (key < (*root)->data)
        (*root)->left = deleteNode(&(*root)->left, key);
    else if (key == (*root)->data)
    {
        // if input key matches the root's value, then
        // check for following cases for termination
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            // case 1: root has no leaves, then remove the root
            *root = NULL;
            return NULL;
        }
        else if ((*root)->left == NULL)
        {
            // case 2: root has one leaf, then make the leaf
            // the new root and remove old root
            node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return *root;
        }
        else if ((*root)->right == NULL)
        {
            node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return *root;
        }
        else
        {
            // case 3: root has two leaves, then find its
            // successor root and switch them
            node *temp = getSuccessorNode((*root)->left);
            // set the data of this node equal to data of successor node
            (*root)->data = temp->data;
            (*root)->left = deleteNode(&(*root)->left, temp->data);
        }
    }
    return *root;
}

/**
 * @brief To count the number of leaves in a tree
 * @param root the pointer to parent node
 * @return int number of leaves present in the tree
 */
int countLeafs(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return countLeafs(root->left) + countLeafs(root->right);
}

int main()
{
    node *root = NULL, *ptr;
    int status = 1, option, key;
    while (status == 1)
    {
        printf("1. Insert 2. Delete 3. Search 4. Display 5. Leaf Count 6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter value to be inserted: ");
            scanf("%d", &key);
            insertNode(&root, key);
            break;
        case 2:
            printf("Enter value to be deleted: ");
            scanf("%d", &key);
            ptr = deleteNode(&root, key);
            if (ptr == NULL)
                printf("Element Not Found\n");
            else
                printf("%d is Deleted\n", ptr->data);
            break;
        case 3:
            printf("Enter value to be searched: ");
            scanf("%d", &key);
            ptr = search(root, key);
            if (ptr == NULL)
                printf("Element Not Found\n");
            else
                printf("%d is Found\n", ptr->data);
            break;
        case 4:
            printf("Inorder : ");
            printInOrder(root);
            printf("\n");

            printf("Preorder : ");
            printPreOrder(root);
            printf("\n");

            printf("Postorder : ");
            printPostOrder(root);
            printf("\n");
            break;
        case 5:
            printf("No. of leafs : %d\n", countLeafs(root));
            break;
        case 6:
            status = 0;
            break;
        default:
            printf("Enter appropriate option.\n");
            break;
        }
    }
    free(ptr);
    purge(&root);
    return 0;
}