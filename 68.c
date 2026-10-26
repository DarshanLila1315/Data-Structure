// . WAP to delete alternate nodes of a doubly linked list.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insertEnd(int data) {
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void display() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteAlternate() {
    struct Node *temp = head;
    struct Node *del;

    while (temp != NULL && temp->next != NULL) {
        del = temp->next;

        temp->next = del->next;

        if (del->next != NULL)
            del->next->prev = temp;

        free(del);
        temp = temp->next;
    }

    printf("Alternate nodes deleted.\n");
}

int main() {
    int n, i, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &data);
        insertEnd(data);
    }

    printf("\nOriginal List: ");
    display();

    deleteAlternate();

    printf("List after deletion: ");
    display();

    return 0;
}
