// WAP to implement Red-Black Tree.



#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

struct Node {
    int data, color;
    struct Node *left, *right, *parent;
};

struct Node *root = NULL;

struct Node* createNode(int data) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));

    n->data = data;
    n->color = RED;
    n->left = n->right = n->parent = NULL;

    return n;
}

void rotateLeft(struct Node *x) {
    struct Node *y = x->right;

    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rotateRight(struct Node *x) {
    struct Node *y = x->left;

    x->left = y->right;

    if (y->right != NULL)
        y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;
}

void fixTree(struct Node *z) {
    struct Node *p, *g, *u;

    while (z != root && z->parent->color == RED) {
        p = z->parent;
        g = p->parent;

        if (p == g->left) {
            u = g->right;

            if (u != NULL && u->color == RED) {
                p->color = BLACK;
                u->color = BLACK;
                g->color = RED;
                z = g;
            } else {
                if (z == p->right) {
                    z = p;
                    rotateLeft(z);
                    p = z->parent;
                    g = p->parent;
                }

                p->color = BLACK;
                g->color = RED;
                rotateRight(g);
            }
        } else {
            u = g->left;

            if (u != NULL && u->color == RED) {
                p->color = BLACK;
                u->color = BLACK;
                g->color = RED;
                z = g;
            } else {
                if (z == p->left) {
                    z = p;
                    rotateRight(z);
                    p = z->parent;
                    g = p->parent;
                }

                p->color = BLACK;
                g->color = RED;
                rotateLeft(g);
            }
        }
    }

    root->color = BLACK;
}

void insert(int data) {
    struct Node *z = createNode(data);
    struct Node *y = NULL;
    struct Node *x = root;

    while (x != NULL) {
        y = x;

        if (data < x->data)
            x = x->left;
        else if (data > x->data)
            x = x->right;
        else {
            free(z);
            printf("Duplicate value not allowed.\n");
            return;
        }
    }

    z->parent = y;

    if (y == NULL)
        root = z;
    else if (data < y->data)
        y->left = z;
    else
        y->right = z;

    fixTree(z);
}

void inorder(struct Node *r) {
    if (r != NULL) {
        inorder(r->left);
        printf("%d(%s) ", r->data,
               r->color == RED ? "R" : "B");
        inorder(r->right);
    }
}

int main() {
    int choice, data;

    do {
        printf("\n1. Insert\n");
        printf("2. Display Inorder\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insert(data);
                break;

            case 2:
                printf("Red-Black Tree: ");
                inorder(root);
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
