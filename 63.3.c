//  WAP to implement  Priority Queue using singly linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node * front = NULL;
Node * rear = NULL;
int queueSize = 0;
int count = 0;

void enqueue(int data, int priority) {
    if (count >= queueSize) {
        printf("Priority queue is full.\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    
    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        Node *current = front;
        while (current->next != NULL &&
               current->next->priority <= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    if (rear == NULL || newNode->next == NULL)
        rear = newNode;
    count++;
    printf("Element inserted successfully.\n");
}

void dequeue(void) {
    if (front == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }

    Node *temp = front;
    printf("Deleted element: %d (priority %d)\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
    count--;
    if (front == NULL)
        rear = NULL;
}

void display(void) {
    if (front == NULL) {
        printf("Priority queue is empty.\n");
        return;
    }

    Node *current = front;
    printf("Priority queue: ");
    while (current != NULL) {
        printf("[%d, p=%d] ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    printf("Enter the size of the priority queue: ");
    if (scanf("%d", &queueSize) != 1 || queueSize <= 0) {
        printf("Invalid queue size.\n");
        return 1;
    }
    
    int choice, data, priority;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter data and priority: ");
                if (scanf("%d %d", &data, &priority) != 2) {
                    printf("Invalid input.\n");
                    return 1;
                }
                enqueue(data, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    while (front != NULL)
        dequeue();
    return 0;
}


