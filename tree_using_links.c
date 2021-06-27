#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * create_node(int x)
{
    struct node * n=(struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->left=NULL;
    n->right=NULL;

    return n;
}
/*
           10
          /  \
         /    \
        20     30
       / \
      /   \
     40    50
*/

void pre_traverse(struct node * p)
{
    if(p!=NULL)
    {
        printf("%d -->",p->data);
        printf("[");
        pre_traverse(p->left);
        printf("]");
        printf("[");
        pre_traverse(p->right);
        printf("]");
    }
    else{
        printf("NULL");
    }
}
int main()
{
    struct node *p0,*p1,*p2,*p3,*p4;
    p0=create_node(10);
    p1=create_node(20);
    p2=create_node(30);
    p3=create_node(40);
    p4=create_node(50);
    p0->left=p1;
    p0->right=p2;
    p1->left=p3;
    p1->right=p4;


    pre_traverse(p0);
    
    return 0;
}
