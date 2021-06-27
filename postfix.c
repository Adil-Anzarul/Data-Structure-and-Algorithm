#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
};
int isEmpty(struct node *p)
{
    if (p == NULL)
        return 1;
    return 0;
}

int isFull(struct node *p)
{
    struct node *p1 = (struct node *)malloc(sizeof(struct node));
    if (p1 == NULL)
        return 1;
    return 0;
}

void push(struct node **ptr, char i)
{
    if (isFull(*ptr))
    {
        printf("Stack Overflow ,can't push element\n");
    }
    else
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->data = i;
        p->next = *ptr;
        *ptr = p;
    }
}

char pop(struct node **ptr)
{
    if (isEmpty(*ptr))
    {
        printf("Stack is empty nothing to pop\n");
    }
    else
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        char ret = (*ptr)->data;
        p = *ptr;
        *ptr = (*ptr)->next;
        free(p);
        return ret;
    }
}
int isOperator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
        return 1;
    return 0;
}
int precedence(char c)
{
    if (c == '*' || c == '/')
        return 3;
    else if (c == '+' || c == '-')
        return 2;
    return 0;
}
char isTop(struct node * sp)
{
    return (sp->data);
}

char* infixToPostfix(char* infix)
{
    char *a = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    struct node *sp=(struct node *)malloc(sizeof(struct node));
    sp->data=' ';
    sp->next=NULL;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            a[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(isTop(sp)))
            {
                push(&sp, infix[i]);
                i++;
            }
            else
            {
                a[j] = pop(&sp);
                j++;
            }
        }

    }
     while (!isEmpty(sp))
        {
            a[j] = pop(&sp);
            j++;
        }
        a[j] = '\0';
        // printf("%s\n",a);

    return a;
}

int main()
{
    char* infix = "b-k+c";
    
    printf("%s\n",infixToPostfix(infix));
    return 0;
}

/*Finally i did it!!!!!!!!!!!!!!!!!!!!*/
