#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
int data;
struct node * left ;
struct node * right;
} node;

void inorder(struct node * p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
struct node * create_node(int val)
{
    struct node * n=(struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}

struct node * search(struct node * ptr,int x)
{
    if(ptr==NULL)
    {return NULL;}
    else if(ptr->data==x)
    {
        return ptr;
    }
    else if(ptr->data>x)
    {
        search(ptr->left,x);
    }
    else 
    {
        search(ptr->right,x);
    }
}

/*
           30
          /  \
         /    \
        20     35
       / \
      /   \
     10    25
*/
int main()
{
    struct node *p0,*p1,*p2,*p3,*p4;
    p0=create_node(30);
    p1=create_node(20);
    p2=create_node(35);
    p3=create_node(10);
    p4=create_node(25);

    p0->left=p1;
    p0->right=p2;
    p1->left=p3;
    p1->right=p4;

    inorder(p0);
    printf("\n");
    struct node * p=search(p0,10);
    if(p==NULL)
    {printf("Element not Found in BST\n");}
    else
    {printf("Element %d is Found in BST\n",p->data);}



    
    return 0;
}

