// WAP to check whether the given tree is symmetric or not.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int isMirror(struct Node *left, struct Node *right) {
    if (left == NULL && right == NULL)
        return 1;

    if (left == NULL || right == NULL)
        return 0;

    return (left->data == right->data &&
            isMirror(left->left, right->right) &&
            isMirror(left->right, right->left));
}

int isSymmetric(struct Node *root) {
    if (root == NULL)
        return 1;

    return isMirror(root->left, root->right);
}

int main() {
    struct Node *root;

    
    root = createNode(8);

    root->left = createNode(5);
    root->right = createNode(5);

    root->left->left = createNode(3);
    root->left->right = createNode(6);

    root->right->left = createNode(6);
    root->right->right = createNode(3);

    if (isSymmetric(root))
        printf("Given tree is symmetric.\n");
    else
        printf("Given tree is not symmetric.\n");

    return 0;
}
