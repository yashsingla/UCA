//time complexity of kth_smalles: O(h) ,h=height of bst
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key,l_count;
    struct node *left,*right;
};

struct node *newNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
   temp->l_count=0;
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

//iterative insertion in BST
void insert(struct node *root,int key)
{
    struct node *temp=root;
    struct node *temp1=NULL;

    while(temp)
    {
        temp1=temp;
        if(key<temp->key)
        {
            (temp->l_count)++;
            temp=temp->left;
        }
        else
            temp=temp->right;
    }

    if(!root)
    {
        root=newNode(key);
    }
    else if(key<temp1->key)
    {
        temp1->left=newNode(key);
    }
    else
        if(key>temp1->key)
    {
        temp1->right=newNode(key);
    }
}

int kth_smallest(struct node *root,int k)
{
    if(!root)
        return -1;

    struct node *temp=root;
  int smallest=-1;
     while(temp)
     {
         if(temp->l_count+1==k){
              smallest=temp->key;
          break;
         }
         else
            if(k>temp->l_count)
         {
             k=k-(temp->l_count+1);
             temp=temp->right;
         }
         else
         {
             temp=temp->left;
         }
     }
return smallest;
}
void inorder(struct node *root)
{
    if(!root)
    return;

    inorder(root->left);
    printf("%d ",root->l_count);
    inorder(root->right);
}

void wrapper(int a[],int n,int k)
{
     struct node *root=newNode(a[0]);
     int i;

     for(i=1;i<n;i++)
     insert(root,a[i]);

    // inorder(root);

   int x=kth_smallest(root,k);
   printf("kth_smallest:%d",x);
}

int main()
{
    int a[]={20,8,22,4,12,10,14};
    int n=sizeof(a)/sizeof(a[0]);
    wrapper(a,n,3);
}
