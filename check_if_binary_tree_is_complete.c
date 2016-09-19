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

int full_binary(struct node *root)
{
        if(root==NULL)
            return 1;

   if(root->left==NULL&&root->right==NULL)
        {
        return 1 ;
        }


    if(root->left!=NULL&&root->right!=NULL)
    {
       return  (full_binary(root->left)&&full_binary(root->right));

    }

  return 0;

}


int main()
{
   //int a[]={40,30,35,20,50,60};
   int a[]={40,20,50,10};
   int x;
   struct node *root=NULL;
   root=insert(root,a[0]);
   insert(root,a[1]);
   insert(root,a[2]);
   insert(root,a[3]);
   //insert(root,a[4]);
   //insert(root,a[5]);

   x=full_binary(root);
   printf("x:%d",x);

}

