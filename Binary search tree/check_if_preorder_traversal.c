//check if given array is in preorder...inefficient code
#include<stdio.h>

struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int n)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->key=n;
    temp->left=temp->right=NULL;
return temp;
};

struct node *insert(struct node *node,int n)
{
    if(node==NULL)
    node=newNode(n);

   if(n<node->key)
   node->left=insert(node->left,n);
   else
    if(n>node->key)
   node->right=insert(node->right,n);

   return node;
};

int b[10],i=0;
void pre_order(struct node *node)
{
    if(node==NULL)
     return;

    b[i++]=node->key;
    pre_order(node->left);
    pre_order(node->right);

}

int main()
{
   int a[]={40,30,35,80,100};

   struct node *root=NULL;
   root=insert(root,a[0]);
   insert(root,a[1]);
   insert(root,a[2]);
   insert(root,a[3]);
   insert(root,a[4]);
   //insert(root,a[5]);
int p=0;
   pre_order(root);
  for(i=0;i<5;i++)

    if(a[i]!=b[i])
   { p=1;
    printf("false");
    break;
   }
    if(p==0)
   printf("true");

}
