#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};


int areIdentical(struct node *root1,struct node *root2)
{
    if(root1==NULL&&root2==NULL)
        return 1;

    if(root1==NULL||root2==NULL)
        return 0;

     return ((root1->data==root2->data)&&
             (areIdentical(root1->left,root2->left))
             &&(areIdentical(root1->right,root2->right)));
}


int isSubtree(struct node *t,struct node *s)
{
    if(s==NULL)
        return 1;

    if(t==NULL)
        return 0;

   if(areIdentical(t,s))
          return 1;

   return isSubtree(t->left,s)||isSubtree(t->right,s);
}

struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return(node);
}

int main()
{

struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);


    struct node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);




 if(isSubtree(T,S))
    printf("yes");
    else
     printf("no");

    return 0;
}
