/*
Doubly linked list -----------
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *previous;
    struct node *next;
};

void printDll(struct node *ptr)
{

    while (ptr->next != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}



void magicPrint(struct node *ptr)
{

    while (ptr->next != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    // printf("%d\n", ptr->data);
     while (ptr->previous != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->previous;
    }
    printf("%d\n", ptr->data);
}

int main()
{
    struct node *first;
    first = (struct node *)malloc(sizeof(struct node));
    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    struct node *third;
    third = (struct node *)malloc(sizeof(struct node));
    struct node *forth;
    forth = (struct node *)malloc(sizeof(struct node));

    first->data = 10;
    first->previous = NULL;
    first->next = second;

    second->data = 20;
    second->previous = first;
    second->next = third;

    third->data = 30;
    third->previous = second;
    third->next = forth;

    forth->data = 40;
    forth->previous = third;
    forth->next = NULL;

    printDll(first);


    printf("------------------------------\n");

    magicPrint(first);

    return 0;
}
