
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        printf("Duplicate value is not allowed.\n");

    return root;
}

Node *search(Node *root, int data)
{
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);

    return search(root->right, data);
}

Node *findMin(Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void displayTree(Node *root, int space)
{
    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");

    printf("%d\n", root->data);

    displayTree(root->left, space);
}

void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void)
{
    Node *root = NULL;
    int choice, data;

    while (1)
    {
        printf("\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search a node\n");
        printf("4. Preorder Traversal\n");
        printf("5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Display Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            if (scanf("%d", &data) != 1)
                goto input_error;

            root = insert(root, data);
            break;

        case 2:
            printf("Enter value to delete: ");
            if (scanf("%d", &data) != 1)
                goto input_error;

            if (search(root, data) == NULL)
                printf("Node not found.\n");
            else
            {
                root = deleteNode(root, data);
                printf("Node deleted successfully.\n");
            }
            break;

        case 3:
            printf("Enter value to search: ");
            if (scanf("%d", &data) != 1)
                goto input_error;

            if (search(root, data) != NULL)
                printf("Node found.\n");
            else
                printf("Node not found.\n");
            break;

        case 4:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 5:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            if (root == NULL)
                printf("Tree is empty.\n");
            else
            {
                printf("Displaying Tree:\n");
                displayTree(root, 0);
                printf("\n");
            }
            break;

        case 8:
            freeTree(root);
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    freeTree(root);
    return 1;

input_error:
    printf("Invalid input. Exiting program.\n");
    freeTree(root);
    return 1;
}
