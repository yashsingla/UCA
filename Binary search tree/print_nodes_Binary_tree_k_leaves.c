//time complexity:O(n)
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

int printLeaves(struct node *root,int k)
{
    if(!root)
     return 0;

   if(!root->left&&!root->right)
        return 1;

      int c=printLeaves(root->left,k)+printLeaves(root->right,k);

      if(c==k)
        printf("%d\t",root->key);

return c;
}


int main()
{
    int k=2;
    struct node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(4);
    root->left->left=newNode(5);
    root->left->right=newNode(6);
    root->right->right=newNode(8);
    root->right->left=newNode(7);
    root->right->left->left=newNode(11);
    root->right->left->right=newNode(12);
    root->left->left->left=newNode(9);
    root->left->left->right=newNode(10);
  int x=printLeaves(root,k);
}
