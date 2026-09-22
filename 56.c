// WAP to remove the duplicates nodes from given sorted Linked List. 
// Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27 
// Output: 1 → 6 → 13 → 27 

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
} node;

node *first = NULL;

void insert_at_end( int x)
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

void remove_duplicates()
{
    node * temp = first;
    while (temp != NULL && temp->link != NULL)
    {
        if (temp->info == temp->link->info)
        {
            temp->link = temp->link->link;
            free(temp->link);
        }
        else
        {
            temp = temp->link;
        }
    }
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

void main()
{
    insert_at_end(1);
    insert_at_end(1);
    insert_at_end(6);
    insert_at_end(13);
    insert_at_end(13);
    insert_at_end(13);
    insert_at_end(27);
    insert_at_end(27);

    printf("Original List: ");
    display();

    remove_duplicates();


    display();
}