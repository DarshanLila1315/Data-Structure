// WAP to remove duplicate elements from a singly linked list.

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
    node *New, *save;
    New = (node *)malloc(sizeof(node));
    New->info = x;
    New->link = NULL;
    if (first == NULL)
    {
        first = New;
        return;
    }
    save = first;
    while (save->link != NULL)
        save = save->link;
    save->link = New;
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

void remove_duplicates()
{
    node *temp = first, *curr;
    while (temp != NULL)
    {
        curr = temp;
        while (curr->link != NULL)
        {
            if (temp->info == curr->link->info)
            {
                node *dup = curr->link;
                curr->link = curr->link->link;
                free(dup);
            }
            else
            {
                curr = curr->link;
            }
        }
        temp = temp->link;
    }
}

void main()
{
    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(20);
    insert_at_end(3);
    insert_at_end(5);
    insert_at_end(3);

    printf("Original list: ");
    display();

    remove_duplicates();

    printf("removing duplicates: ");
    display();
}