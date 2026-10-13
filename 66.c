#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
    int c, e;
    struct Term *next;
} Term;

Term *newTerm(int c, int e)
{
    Term *t = malloc(sizeof(*t));
    if (!t)
        exit(EXIT_FAILURE);
    t->c = c;
    t->e = e;
    t->next = NULL;
    return t;
}

void insert(Term *p, int c, int e)
{
    Term *q = p, *t;
    if (!c)
        return;
    while (q && q->e > e)
        q = q->next;
    if (q && q->e == e)
    {
        q->c += c;
        return;
    }
    t = newTerm(c, e);
    t->next = q;
    q = t;
}
    
Term *add(Term *a, Term *b)
{
    Term *s = NULL;
    for (; a; a = a->next)
        insert(&s, a->c, a->e);
    for (; b; b = b->next)
        insert(&s, b->c, b->e);
    return s;
}

void display(Term *p)
{
    int first = 1, c;
    if (!p)
    {
        printf("0");
        return;
    }
    for (; p; p = p->next)
        if (p->c)
        {
            c = p->c;
            printf(first ? (c < 0 ? "-" : "") : (c < 0 ? " - " : " + "));
            if (abs(c) != 1 || !p->e)
                printf("%d", abs(c));
            if (p->e > 0)
                printf("x%s%d", p->e > 1 ? "^" : "", p->e > 1 ? p->e : 0);
            first = 0;
        }
    if (first)
        printf("0");
}

void freePoly(Term *p)
{
    while (p)
    {
        Term *n = p->next;
        free(p);
        p = n;
    }
}

int main(void)
{
    Term *a = NULL, *b = NULL, *s;
    int n, c, e, i;

    for (i = 0; i < 2; i++)
    {
        printf("Enter number of terms: ");
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d%d", &c, &e);
            insert(i ? &b : &a, c, e);
        }
    }
    s = add(a, b);
    printf("\nFirst: ");
    display(a);
    printf("\nSecond: ");
    display(b);
    printf("\nSum: ");
    display(s);
    printf("\n");
    freePoly(a);
    freePoly(b);
    freePoly(s);
    return 0;
}
