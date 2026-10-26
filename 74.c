// WAP to construct a binary tree from given Inorder and Preorder traversal
// sequence


#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *left, *right;
};

char inorder[50], preorder[50];
int preIndex = 0;

struct Node* createNode(char data) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int search(char data, int start, int end) {
    int i;

    for (i = start; i <= end; i++) {
        if (inorder[i] == data)
            return i;
    }

    return -1;
}

struct Node* buildTree(int start, int end) {
    int pos;
    struct Node *root;

    if (start > end)
        return NULL;

    root = createNode(preorder[preIndex++]);

    if (start == end)
        return root;

    pos = search(root->data, start, end);

    root->left = buildTree(start, pos - 1);
    root->right = buildTree(pos + 1, end);

    return root;
}

void displayInorder(struct Node *root) {
    if (root != NULL) {
        displayInorder(root->left);
        printf("%c ", root->data);
        displayInorder(root->right);
    }
}

void displayPreorder(struct Node *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}

int main() {
    struct Node *root;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter Inorder sequence: ");
    scanf("%49s", inorder);

    printf("Enter Preorder sequence: ");
    scanf("%49s", preorder);

    preIndex = 0;
    root = buildTree(0, n - 1);

    printf("\nInorder traversal: ");
    displayInorder(root);

    printf("\nPreorder traversal: ");
    displayPreorder(root);

    return 0;
}
