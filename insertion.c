#include<stdio.h>
struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int item)
{    struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->key=item;
     temp->left=NULL;
     temp->right=NULL;
     return temp;
};

struct node *insert(struct node *root,int n)
{
    if(root==NULL)
    return newNode(n);

    if(n<root->key)
        root->left=insert(root->left,n);
    else
        if(n>root->key)
      root->right=insert(root->right,n);

    return root;
};

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
       printf("%d\n",root->key);
        inorder(root->right);
    }

}


int main()
{
    struct node *root=NULL;
  root=insert(root,50);
  insert(root,30);
  insert(root,20);
  insert(root,40);
  insert(root,60);
  insert(root,70);
  insert(root,80);
  inorder(root);
}
