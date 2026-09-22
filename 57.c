//  WAP to check whether 2 singly linked lists are same or not.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
} node;

node *first = NULL;

void insert_at_end(node *list, int x)
{
    node *New, *save;
    New = (node *)malloc(sizeof(node));
    New->info = x;
    New->link = NULL;
    if (list == NULL)
    {
        list = New;
        return;
    }
    save = list;
    while (save->link != NULL)
        save = save->link;
    save->link = New;
}

int are_same(node *list1, node *list2)
{
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->info != list2->info)
            return 0; // Lists are not same
        list1 = list1->link;
        list2 = list2->link;
    }
    return (list1 == NULL && list2 == NULL); 
}
void display(node *list)
{
    node *temp = list;
    while (temp != NULL)
    {
        printf("%d  ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

void main()
{
    node *list1 = (node *)malloc(sizeof(node));
    node *list2 = (node *)malloc(sizeof(node));
    insert_at_end(list1, 1);
    insert_at_end(list1, 2); 
    insert_at_end(list1, 3);

    display(list1);
    
    insert_at_end(list2, 1);
    insert_at_end(list2, 2);
    insert_at_end(list2, 3);
    display(list2);
    if (are_same(list1, list2))
        printf("same.\n");
    else
        printf(" not  same.\n");


}