#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
} node;

node *insert_at_end(node *list, int x)
{
    node *New = (node *)malloc(sizeof(node));
    New->info = x;
    New->link = NULL;

    if (list == NULL)
        return New;

    node *save = list;
    while (save->link != NULL)
        save = save->link;
    save->link = New;
    return list;
}

/* Recursive comparison */
int are_same(node *a, node *b)
{
    while (a != NULL && b != NULL)
    {
        if (a->info != b->info)
            return 0;
        a = a->link;
        b = b->link;
    }
    return (a == NULL && b == NULL);
}

void display(node *list)
{
    while (list)
    {
        printf("%d ", list->info);
        list = list->link;
    }
    printf("\n");
}

int main(void)
{
    node *list1 = NULL, *list2 = NULL;

    list1 = insert_at_end(list1, 1);
    list1 = insert_at_end(list1, 2);
    list1 = insert_at_end(list1, 3);

    list2 = insert_at_end(list2, 1);
    list2 = insert_at_end(list2, 2);
    list2 = insert_at_end(list2, 3);

    display(list1);
    display(list2);

    if (are_same(list1, list2))
        printf("same.\n");
    else
        printf("not same.\n");

    return 0;
}
