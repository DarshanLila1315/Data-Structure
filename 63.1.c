// WAP to implement Simple Queue using singly linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node * front = NULL;
Node * rear = NULL;
int queueSize = 0;
int count = 0;

void enqueue(int value) {
    if (count == queueSize) {
        printf("Queue overflow\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        count++;
        return;
    }

    rear->next = newNode;
    rear = newNode;
    count++;
}

int dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return -1; 
    }
    Node* temp = front;
    int y = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    count--;
    free(temp);
    printf("%d dequeued from queue\n", y);
    return y;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    printf("Enter size of Queue: ");
    scanf("%d", &queueSize);
    if (queueSize <= 0) {
        printf("Queue size must be positive\n");
        return 1;
    }
    int choice, value;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}