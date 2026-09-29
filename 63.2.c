// WAP to implement  Circular Queue  using singly linked list. 

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
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = front;
    count++;
    printf("%d enqueued to queue\n", value);
}

int dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return -1; 
    }
    Node* temp = front;
    int y = temp->data;
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; 
    }
    free(temp);
    count--;
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
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    printf("Enter the size of the circular queue: ");
    scanf("%d", &queueSize);
    if (queueSize <= 0) {
        printf("Queue size must be positive\n");
        return 1;
    }
    int choice, value;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                if (scanf("%d", &value) == 1) {
                    enqueue(value);
                } else {
                    printf("Invalid input\n");
                    while (getchar() != '\n');
                }
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