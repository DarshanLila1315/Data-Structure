// 59. WAP to swap Kth node from beginning with Kth node from end in a singly linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

struct Node *createNode(int data)
{
    Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int data)
{
    Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Swap kth node from beginning and kth node from end
void swapKth(struct Node *head, int k)
{
    int n = 0;
    struct Node *temp = head;

    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }

    if (k <= 0 || k > n)
    {
        printf("Invalid value of k\n");
        return;
    }

    if (2 * k - 1 == n)
        return;

    Node *prev1 = NULL, *curr1 = head;
    Node *prev2 = NULL, *curr2 = head;

    for (int i = 1; i < k; i++)
    {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    for (int i = 1; i < n - k + 1; i++)
    {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (prev1 != NULL)
        prev1->next = curr2;
    else
        head = curr2;

    if (prev2 != NULL)
        prev2->next = curr1;
    else
        head = curr1;

    Node *tempNext = curr1->next;
    curr1->next = curr2->next;
    curr2->next = tempNext;
}

int main()
{
    Node *head = NULL;
    int n, data, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Original list: ");
    display(head);

    swapKth(head, k);

    printf("After swapping: ");
    display(head);

    return 0;
}
