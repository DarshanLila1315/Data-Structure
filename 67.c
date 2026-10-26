//  Write a menu driven program to implement following operations on the doubly
// linked list.
// • Insert a node at the front of the linked list.
// • Delete a node from specified position.
// • Insert a node at the end of the linked list.
// • Display all nodes.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert node at the front
void insertFront() {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;

    printf("Node inserted at front.\n");
}

// Delete node from specified position
void deletePosition() {
    struct Node *temp = head;
    int pos, i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    for (i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted successfully.\n");
}

// Insert node at the end
void insertEnd() {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node inserted at end.\n");
}

// Display all nodes
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main menu
int main() {
    int choice;

    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Delete from Position\n");
        printf("3. Insert at End\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFront();
                break;

            case 2:
                deletePosition();
                break;

            case 3:
                insertEnd();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
