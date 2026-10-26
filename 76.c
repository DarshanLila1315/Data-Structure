// Given a binary tree, determine if it is height-balanced (A height-balanced binary
// tree is a binary tree in which the depth of the two subtrees of every node never
// differs by more than one)


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

int height(struct Node *root) {
    int leftHeight, rightHeight;

    if (root == NULL)
        return 0;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if (leftHeight == -1 || rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main() {
    struct Node *root;

    // Create the tree
    root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    if (height(root) != -1)
        printf("TRUE: Tree is height-balanced.\n");
    else
        printf("FALSE: Tree is not height-balanced.\n");

    return 0;
}
