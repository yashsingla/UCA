//A complete BT has complete nodes at every level except last level may or may not have complete nodes
// A tree in which left child of a node is NULL and right is NON-NULL at any level, even at last level is not a complete binary tree

#include<iostream>
#include<queue>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

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
//very efficient, O(n)
int isCompleteBT(struct node *root)
{
    queue<struct node*>q;
    q.push(root);
    int flag=0;

    while(!q.empty())
    {
        struct node *temp=q.front();
         q.pop();
        if(temp->left)
        {
            if(flag==1)
                return 0;

           q.push(root->left);
        }
        else
            flag=1;

            if(temp->right)
        {
            if(flag==1)
                return 0;

           q.push(root->right);
        }
        else
            flag=1;

    }
    return 1;
}

int main()
{
   struct node *root  = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);
  //root->right->right = newNode(6);

  if ( isCompleteBT(root) == true )
      printf ("Complete Binary Tree");
  else
      printf ("NOT Complete Binary Tree");

}

/*
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


int full_binary(struct node *root)
{
        if(root==NULL)
            return 1;

   if(root->left==NULL&&root->right==NULL)
        {
        return 1 ;
        }


    if(root->left==NULL||root->right==NULL)
      return 0;

       return  (full_binary(root->left)&&full_binary(root->right));

}
*/
