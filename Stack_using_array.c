#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} Stack;

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}

void push(struct stack *ptr, int i)
{
    if (isFull(ptr) == 1)
    {
        printf("Stack overflow!!!!\nCan't push %d\n", i);
    }
    else
    {
        ptr->arr[ptr->top + 1] = i;
        ptr->top = ptr->top + 1;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr) == 1)
    {
        printf("Stack is Empty!!!!\nNothing to pop\n");
        return 0;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        printf("Element %d is popped from stack\n", value);
    }
}

void stackTop(struct stack *p)
{
    if (isEmpty(p) == 0)
        printf("Top most element of stack is %d\n", p->arr[p->top]);
    else
        printf("Stack is empty\n");
}

void stackBottom(struct stack *p)
{
    if (isEmpty(p) == 0)
        printf("Bottom most element of stack is %d\n", p->arr[0]);
    else
        printf("Stack is empty\n");
}

void peek(Stack *p, int position)
{
    int index = p->top - position + 1;
    if (index < 0)
        printf("Invalid position input\n");
    else
        printf("Element at %d position is %d\n", position, p->arr[index]);
}

int main()
{
    struct stack *sp;
    sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    sp->top = -1;

    // printf("%d\n", isEmpty(sp));
    // printf("%d\n", isFull(sp));

    push(sp, 7);
    push(sp, 10);
    push(sp, 15);
    push(sp, 20);
    push(sp, 25);
    push(sp,100);
    push(sp,150);
    push(sp,200);

    // pop(sp);

    // stackTop(sp);
    // stackBottom(sp);
    // pop(sp);
    // stackTop(sp);

    // peek(sp, 6);

    for(int j=1;j<=sp->top+1;j++)
    {
        peek(sp,j);
    }

    return 0;
}