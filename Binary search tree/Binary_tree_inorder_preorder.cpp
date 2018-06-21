#include<iostream>
using namespace std;

struct node
{
    int key;
    struct node *left,*right;
};

struct node *new_node()
{
    struct node *temp=new node;
    temp->key=0;
    temp->left=temp->right=NULL;
    return temp;
};

int search_index(int inorder[],int inorderStart,int inoderEnd,int key)
{
    int i;
    for(i=inorderStart;i<=inoderEnd;i++)
        if(inorder[i]==key)
             return i;
}

struct node *convert(int inorder[],int preorder[],int inorderStart,int inorderEnd)
{
    static int preIndex=0;

    if(inorderStart>inorderEnd)
        return NULL;

    struct node *temp=new_node();
    temp->key=preorder[preIndex];

    preIndex++;

  if(inorderStart==inorderEnd)
    return temp;

   int inorder_index=search_index(inorder,inorderStart,inorderEnd,temp->key);

   temp->left=convert(inorder ,preorder ,inorderStart ,inorder_index-1);
   temp->right=convert(inorder ,preorder ,inorder_index+1 ,inorderEnd);
  return temp;
}

void inorder_display(struct node *temp)
{
    if(!temp)
        return;
    inorder_display(temp->left);
    cout<<temp->key<<" ";
     inorder_display(temp->right);
}

int main()
{
    int inorder[]={4,2,5,1,6,3};
    int n=sizeof(inorder)/sizeof(inorder[0]);
    int preorder[]={1,2,4,5,3,6};

    struct node *temp=convert(inorder ,preorder ,0 ,n-1);
    inorder_display(temp);
}
