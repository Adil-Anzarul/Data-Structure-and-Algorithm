#include <stdio.h>
#include <stdlib.h>

int count = 0;
int set_limit = 0;
struct node
{
    int data;
    struct node *next;
};

int stackLimit(struct node *p)
{

    if (count < set_limit)
        return 1;
    return 0;
}

int isEmpty(struct node *p)
{
    if (p == NULL)
        return 1;
    return 0;
}

int isFull(struct node *p)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
        return 1;
    return 0;
}

void push(struct node **ptr, int x)
{
    if (isFull(*ptr) == 1 || stackLimit(*ptr) == 0)
        printf("Stack is Overflow\n");
    else
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->next = *ptr;
        p->data = x;
        *ptr = p;
        count++;
    }
}

void pop(struct node **ptr)
{
    if (isEmpty(*ptr) == 1)
        printf("Stack is Empty\tNothing to pop\n");
    else
    {
        struct node *p;
        int u = (*ptr)->data;
        printf("%d is popped\n", u);
        p = *ptr;
        *ptr = (*ptr)->next;
        free(p);
        count--;
    }
}

void ElementTraverse(struct node *top)
{
    for (; top != NULL; top = top->next)
        printf("\t%d\n", top->data);
}

void peek(struct node *ptr, int position)
{
    for (int i = 1; (i <= position - 1 && ptr != NULL); i++)
        ptr = ptr->next;
    if (ptr != NULL)
        printf("\t%d\n", ptr->data);
    else
        printf("\tInvalid input");
}

int isTop(struct node *p)
{
    if (isEmpty(p))
        return -1;
    else
        return p->data;
}

int isBottom(struct node *p)
{
    while (p->next != NULL)
        p = p->next;
    return p->data;
}

int main()
{
    struct node *top = NULL;

    printf("Enter the maximum number of elements u wanna have in stack\n");
    int n, m;
    scanf("%d", &n);
    m = n;
    set_limit = n;

    // n=8;
    printf("Enter the elements in stack\n");
    while (n)
    {
        int x;
        scanf("%d", &x);
        push(&top, x);
        n--;
    }

    // push(&top,10);
    // push(&top,20);
    // push(&top,30);
    // push(&top,40);
    // push(&top,50);
    // // pop(&top);
    // push(&top,60);
    // push(&top,160);
    // push(&top,77);
    // push(&top,74);
    // // ElementTraverse(top);
    // // pop(&top);
    // // pop(&top);
    // // pop(&top);
    // ElementTraverse(top);

    // for(int i=1;i<=m;i++)
    //     peek(top, i);

    printf("The element at top is %d\n", isTop(top));
    printf("The element at bottom is %d\n", isBottom(top));

    return 0;
}