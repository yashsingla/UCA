//time complexity: O(N)

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int key)
{
    struct node *temp=(struct  node*)malloc(sizeof(struct node));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
};

struct node *insert(struct node *root,int key)
{
    if(root==NULL){
    return  newNode(key);
    }

    if(key<root->key)
        root->left=insert(root->left,key);
    else
        root->right=insert(root->right,key);

return root;
}

struct node *preToBST(int a[],int n,int key,int *size,int min,int max)
{
    if(*size>=n)
        return NULL;

    struct node *root=NULL;

   if(key>min&&key<max)
   {
       root=newNode(key);
       *size=*size+1;

       if(*size<n)
       {
           root->left=preToBST(a,n,a[*size],size,min,key);
           root->right=preToBST(a,n,a[*size],size,key,max);
       }
   }

return root;
}

void inorder(struct node *root)
{
      if(root==NULL)
         return;

     inorder(root->left);
     printf("%d ",root->key);
     inorder(root->right);
}

void wrapper(int a[],int n)
{
    int size=0;
    struct node *root=NULL;
    root=preToBST(a,n,a[0],&size,INT_MIN,INT_MAX);
    inorder(root);
}

int main()
{
int a[]={15,5,3,1,4,10,17,25,20,30};
int n=sizeof(a)/sizeof(a[0]);
wrapper(a,n);
}
