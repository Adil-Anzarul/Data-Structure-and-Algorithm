#include <stdio.h>
#include <malloc.h>

static int i = 0;
static int arr[100];

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int x)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

void inOrder(struct node *p)
{
    if (p != NULL)
    {
        inOrder(p->left);
        printf("%d ",p->data);
        arr[i] = (p->data);
        i++;
        inOrder(p->right);
    }
}

int isBST(struct node *p)
{
    inOrder(p);

    int j = 0;
    for (j = 0; j < i - 1; j++)
    {
        if (arr[j] >= arr[j + 1])
            return 0;
    }
    return 1;
}



int main()
{
    struct node *p0, *p1, *p2, *p3, *p4, *p5;
    p0 = create_node(50);
    p1 = create_node(40);
    p2 = create_node(60);
    p3 = create_node(30);
    p4 = create_node(45);
    p5 = create_node(20);

// struct node * po=NULL;

    p0->left = p1;
    p0->right = p2;
    p1->left = p3;
    p1->right = p4;
    p3->left = p5;
    /*
             50(p0)
            /     \
           /       \
          40(p1)  60(p2)
         /    \
        /      \
       30(p3)  45(p4)
       /
      /
    20(p5)
*/


    if(isBST(p0))
    printf("<-----It is a BST\n");
    else
    printf("<-----Not a BST\n");

    return 0;
}