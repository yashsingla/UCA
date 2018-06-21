#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *newNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

int fun(struct node *root,int sum)
{
      if(!root)
    return (sum==0) ;

int subsum=sum-root->key;

   if(subsum==0&&!root->left&&!root->right)
                  return 1;

      int ans=0;
      ans=ans||fun(root->left,subsum);
      ans=ans||fun(root->right,subsum);

     return ans;
}

int wrapper(struct node *root,int sum)
{
   return fun(root,sum);
}

int main()
{
int sum=14;
struct node *root=newNode(10);
root->left=newNode(8);
root->left->left=newNode(3);
root->right=newNode(2);
root->right->left=newNode(2);
root->left->right=newNode(5);

if(wrapper(root,sum))
    cout<<"yes";
else
    cout<<"NO";
}
