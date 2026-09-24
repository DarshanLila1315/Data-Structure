//  WAP to swap two consecutive nodes in the linked list. Don’t change the values of nodes, implement by changing the link of the nodes.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
} node;

node *first = NULL;

void insert_at_end(int x)
{
    node *New, *temp;
    New = (node *)malloc(sizeof(node));
    New->info = x;
    New->link = NULL;

    if (first == NULL)
    {
        first = New;
        return;
    }

    temp = first;
    while (temp->link != NULL)
        temp = temp->link;

    temp->link = New;
}

void display()
{
    node *temp = first;
    while (temp != NULL)
    {
        printf("%d  ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

void swap_consecutive_nodes()
{
    if (first == NULL || first->link == NULL)
        return;

    node *prev = NULL;
    node *curr = first;

    while (curr != NULL && curr->link != NULL)
    {
        node *next = curr->link;

        curr->link = next->link;
        next->link = curr;

        if (prev == NULL)
            first = next; 
        else
            prev->link = next; 

        prev = curr; 
        curr = curr->link; 
    }
}

void main()
{
    int n, x;
    printf("Enter size of list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &x);
        insert_at_end(x);
    }

    printf("Original linked list: ");
    display();

    swap_consecutive_nodes();

    printf("Linked list after swapping consecutive nodes: ");
    display();
}