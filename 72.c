// WAP to find the smallest and largest elements in the Binary Search Tree.  


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

int findSmallest(struct Node* root) {
    while (root->left != NULL)
        root = root->left;

    return root->data;
}

int findLargest(struct Node* root) {
    while (root->right != NULL)
        root = root->right;

    return root->data;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("BST must contain at least one node.\n");
        return 0;
    }

    printf("Enter node values:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder Traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    printf("Smallest element = %d\n",
           findSmallest(root));

    printf("Largest element = %d\n",
           findLargest(root));

    return 0;
}
