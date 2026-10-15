// WAP  to  implement  phone  book  dictionary  using  Binary  Search  Tree  which 
// provides following operations: 
// • Add new entry in phone book  
// • Remove entry from phone book 
// • Search phone number  
// • List all entries in ascending order of name  
// • List all entries in descending order of name


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[15];
    struct Node *left, *right;
};

struct Node* createNode(char name[], char phone[]) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node* root,
                    char name[], char phone[]) {
    if (root == NULL)
        return createNode(name, phone);

    int cmp = strcmp(name, root->name);

    if (cmp < 0)
        root->left = insert(root->left, name, phone);
    else if (cmp > 0)
        root->right = insert(root->right, name, phone);
    else {
        strcpy(root->phone, phone);
        printf("Name already exists. Phone updated.\n");
    }

    return root;
}

struct Node* search(struct Node* root, char name[]) {
    if (root == NULL || strcmp(name, root->name) == 0)
        return root;

    if (strcmp(name, root->name) < 0)
        return search(root->left, name);

    return search(root->right, name);
}

struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

struct Node* deleteNode(struct Node* root, char name[]) {
    if (root == NULL)
        return NULL;

    int cmp = strcmp(name, root->name);

    if (cmp < 0)
        root->left = deleteNode(root->left, name);
    else if (cmp > 0)
        root->right = deleteNode(root->right, name);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);

        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);

        root->right = deleteNode(root->right, temp->name);
    }

    return root;
}

void ascending(struct Node* root) {
    if (root != NULL) {
        ascending(root->left);
        printf("%-25s %s\n", root->name, root->phone);
        ascending(root->right);
    }
}

void descending(struct Node* root) {
    if (root != NULL) {
        descending(root->right);
        printf("%-25s %s\n", root->name, root->phone);
        descending(root->left);
    }
}

int main() {
    struct Node* root = NULL;
    struct Node* result;
    int choice;
    char name[50], phone[15];

    do {
        printf("\n--- PHONE BOOK DICTIONARY ---\n");
        printf("1. Add new entry\n");
        printf("2. Remove entry\n");
        printf("3. Search phone number\n");
        printf("4. List entries in ascending order\n");
        printf("5. List entries in descending order\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %49[^\n]", name);

                printf("Enter phone number: ");
                scanf(" %14s", phone);

                root = insert(root, name, phone);
                printf("Entry added successfully.\n");
                break;

            case 2:
                printf("Enter name to remove: ");
                scanf(" %49[^\n]", name);

                result = search(root, name);

                if (result != NULL) {
                    root = deleteNode(root, name);
                    printf("Entry removed successfully.\n");
                } else {
                    printf("Entry not found.\n");
                }
                break;

            case 3:
                printf("Enter name to search: ");
                scanf(" %49[^\n]", name);

                result = search(root, name);

                if (result != NULL)
                    printf("Name: %s\nPhone: %s\n",
                           result->name, result->phone);
                else
                    printf("Entry not found.\n");
                break;

            case 4:
                printf("\nName                     Phone Number\n");
                printf("---------------------------------------------\n");
                ascending(root);
                break;

            case 5:
                printf("\nName                     Phone Number\n");
                printf("---------------------------------------------\n");
                descending(root);
                break;

            case 6:
                printf("Exiting Phone Book.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
