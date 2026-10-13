
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int isSameTree(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;

    if (root1 == NULL || root2 == NULL)
        return 0;

    return (root1->data == root2->data &&
            isSameTree(root1->left, root2->left) &&
            isSameTree(root1->right, root2->right));
}

int main() {
    struct Node* root1 = createNode(3);
    root1->left = createNode(2);
    root1->right = createNode(4);
    root1->left->right = createNode(1);

    struct Node* root2 = createNode(3);
    root2->left = createNode(2);
    root2->right = createNode(4);
    root2->left->right = createNode(1);

    if (isSameTree(root1, root2))
        printf("Given trees are same\n");
    else
        printf("Given trees are not same\n");

    return 0;
}
