// WAP to implement 2-3 Tree.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key[2];
    struct Node *child[3];
    int n;
};

struct Node *createNode(int key) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->key[0] = key;
    newNode->key[1] = 0;
    newNode->n = 1;

    newNode->child[0] = NULL;
    newNode->child[1] = NULL;
    newNode->child[2] = NULL;

    return newNode;
}

void insert(struct Node **root, int key) {
    struct Node *temp, *newNode;
    int i;

    if (*root == NULL) {
        *root = createNode(key);
        return;
    }

    temp = *root;

    while (temp->child[0] != NULL) {
        if (key < temp->key[0])
            temp = temp->child[0];
        else if (temp->n == 1 || key < temp->key[1])
            temp = temp->child[1];
        else
            temp = temp->child[2];
    }

    if (temp->n == 1) {
        if (key < temp->key[0]) {
            temp->key[1] = temp->key[0];
            temp->key[0] = key;
        } else {
            temp->key[1] = key;
        }
        temp->n = 2;
    } else {
        printf("Leaf node is full. Split required.\n");
        printf("This simple version does not support splitting.\n");
    }
}

void display(struct Node *root) {
    int i;

    if (root == NULL)
        return;

    for (i = 0; i < root->n; i++) {
        display(root->child[i]);
        printf("%d ", root->key[i]);
    }

    display(root->child[root->n]);
}

int main() {
    struct Node *root = NULL;
    int choice, key;

    do {
        printf("\n\n--- 2-3 Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(&root, key);
                break;

            case 2:
                printf("Tree elements: ");
                display(root);
                printf("\n");
                break;

            case 3:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}
