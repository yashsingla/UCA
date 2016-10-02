#include<stdio.h>
#include<stdlib.h>

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

struct node *lca(struct node *root,int n1,int n2)
{

    if(root==NULL)
        return NULL;

  if(n1<root->key&&n2<root->key)
       return lca(root->left,n1,n2);

  if(n1>root->key&&n2>root->key)
       return lca(root->right,n1,n2);

return root;

};


int main()
{
    struct node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
    root->left->left->left = newNode(0);
    root->right->right->right = newNode(14);
    struct node *root1=lca(root,6,2);
    printf("LCA is:%d\n",root1->key);

}
