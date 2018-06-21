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

void fun(struct node *root,int sum,vector<int>&v)
{
      if(!root)
        return;

      v.push_back(root->key);

      fun(root->left,sum,v);
      fun(root->right,sum,v);

      int f=0;
      int i;
      for(i=v.size()-1;i>=0;i--)
      {
          f+=v[i];
          if(f==sum)
          {
              int j;
              for(j=i;j<v.size();j++)
                 cout<<v[j]<<" ";
                 cout<<endl;
          }
      }
   v.pop_back();
}

void wrapper(struct node *root,int sum)
{
    vector<int>v;
    fun(root,sum,v);
}


int main()
{
int sum=5;
struct node *root=newNode(1);
root->left=newNode(3);
root->left->left=newNode(2);
root->left->right=newNode(1);
root->right=newNode(-1);
root->right->left=newNode(4);
root->right->right=newNode(5);
root->right->left->left=newNode(1);
root->right->left->right=newNode(2);
root->right->right->right=newNode(6);

wrapper(root,sum);
}
