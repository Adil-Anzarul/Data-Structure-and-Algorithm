#include <stdio.h>
#include <stdlib.h>

struct DEQueue *f = NULL;
struct DEQueue *r = NULL;

struct DEQueue
{
    int data;
    struct DEQueue *next;
};

void enqueue(int x)
{
    struct DEQueue *n = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    if (n == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = x;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
        printf("Enqueued element %d\n", x);
    }
}

void dequeue()
{
    struct DEQueue *ptr = f;
    if (f == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Dequeued element %d\n", f->data);
        f = f->next;
        free(ptr);
    }
}
void isTraverse()
{
    struct DEQueue *fi = f;
    struct DEQueue *ri = r;
    printf("The elements of Queue are----------------\n");
    if(fi!=NULL)
    while (fi != ri->next)
    {
        printf("%d\n", fi->data);
        fi = fi->next;
    }
    else
    printf("Queue is empty\n");
    printf("-----------------------------------------\n");
}

void enqueueF(int x)
{
    struct DEQueue *n = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    if (n == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = x;
        n->next = f;
        f = n;
        printf("Enqueued element %d (in front)\n", x);
    }
}

void dequeueR()
{
    struct DEQueue *ptr = r;
    if (f == NULL)
    {
        printf("Queue is empty\n");
    }
    else if(f->next==NULL)
    {
        printf("Dequeued element %d (from last)\n",f->data);
        f=NULL;
    }
    else
    {
        struct DEQueue *init = f;
        while (init->next->next != NULL)
        {
            init = init->next;
        }
        r = init;
        int a=r->next->data;
        r->next = NULL;
        free(ptr);
        printf("Dequeued element %d (from last)\n",a);
    }
}

int main()
{

    enqueue(10);
    enqueue(20);
    enqueueF(50);
    enqueueF(60);
    dequeue();
    enqueueF(100);
    dequeueR();

    // isTraverse();


    // dequeueR();
    // dequeueR();
    // dequeueR();
    // dequeueR();
    // dequeueR();

    isTraverse();

    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();

    // isTraverse();
    return 0;
}
