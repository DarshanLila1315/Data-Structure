/* WAP to perform given operation in the linked list. There exist a Linked List. Add
a node that contains the GCD of those two nodes between every pair adjacent
node of Linked List. */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
} node;

node *first = NULL;

void insert_at_front(int x)
{
    node *New;
    New = (node *)malloc(sizeof(node));
    New->info = x;
    New->link = first;
    first = New;
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

int find_gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void insert_gcd_nodes()
{
    node *temp = first;
    while (temp != NULL && temp->link != NULL)
    {
        int gcd = find_gcd(temp->info, temp->link->info);
        node *New = (node *)malloc(sizeof(node));
        New->info = gcd;
        New->link = temp->link;
        temp->link = New;
        temp = New->link;
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
        insert_at_front(x);
    }

    printf("Original Linked List: ");
    display();

    insert_gcd_nodes();

    printf("Linked List after inserting GCD nodes: ");
    display();
}