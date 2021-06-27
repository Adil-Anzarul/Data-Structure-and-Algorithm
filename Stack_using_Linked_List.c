#include<stdio.h>
#include<stdlib.h>

int count=0;

struct node
{
    int data;
    struct node * next;
};

int stackLimit(struct node *p)
{
    int set_limit=8;
    if(count<set_limit)
    return 1;
    return 0;
}

int isEmpty(struct node *p)
{
    if(p==NULL)
    return 1;
    return 0;
}

int isFull(struct node *p)
{
    struct node * n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL)
    return 1;
    return 0;
}

void push(struct node **ptr,int x)
{
    if(isFull(*ptr)==1 || stackLimit(*ptr)==0)
    printf("Stack is Overflow\n");
    else
    {
    struct node * p=(struct node*)malloc(sizeof(struct node));
    p->next=*ptr;
    p->data=x;
    *ptr=p;
    count++;
    }
}

void pop(struct node **ptr)
{
    if(isEmpty(*ptr)==1)
    printf("Stack is Empty\tNothing to pop\n");
    else
    {
    struct node * p;
    int u=(*ptr)->data;
    printf("%d is popped\n",u);
    p=*ptr;
    *ptr=(*ptr)->next;
    free(p);
    count--;
    }
}

void ElementTraverse(struct node *top)
{
    for(;top!=NULL;top=top->next)
    printf("\t%d\n",top->data);
}


int main()
{
    struct node * top=NULL;

    push(&top,10);
    push(&top,20);
    push(&top,30);
    push(&top,40);
    push(&top,50);
    // pop(&top);
    push(&top,60);
    push(&top,160);
    push(&top,77);
    push(&top,74);
    // ElementTraverse(top);
    // pop(&top);
    // pop(&top);
    // pop(&top);
    ElementTraverse(top);
    return 0;
}