//  Write a menu driven program to implement following operations on the circular  linked list. 
// • Insert a node at the front of the list. 
// • Insert a node at the end of the list. 
// • Delete the first node of the list. 
// • Delete the last node of the list. 
// • Delete a node from specified position of the list. 
// • Display all nodes.


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;
int count = 0;

void insertAtFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    count++;
}

void insertAtEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    count++;
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
    }
    free(temp);
    count--;
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        while (temp->next != tail) {
            temp = temp->next;
        }
        free(tail);
        tail = temp;
        tail->next = head;
    }
    count--;
}

void deleteAtPosition(int position) {
    if (position < 1 || position > count) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        deleteFirst();
        return;
    }
    if (position == count) {
        deleteLast();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    count--;
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}


void menu() {
    int choice, value, position;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete first node\n");
        printf("4. Delete last node\n");
        printf("5. Delete node at position\n");
        printf("6. Display list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertAtFront(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFirst();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

int main(void) {
    menu();
    return 0;
}