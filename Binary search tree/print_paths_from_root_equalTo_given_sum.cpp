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

void fun(struct node *root,int sum,vector<int>&v,int *p)
{
      if(!root)
        return;

      v.push_back(root->key);
      (*p)=(*p)+root->key;

      if((*p)==sum)
      { int i;
          for(i=0;i<v.size();i++)
            cout<<v[i]<<" ";

          cout<<endl;

        }

      fun(root->left,sum,v,p);
      fun(root->right,sum,v,p);

      (*p)=(*p)-root->key;
      v.pop_back();
}

void wrapper(struct node *root,int sum)
{
    vector<int>v;
    int p=0;
    fun(root,sum,v,&p);
}


int main()
{
int sum=38;
struct node *root=newNode(10);
root->left=newNode(28);
root->right=newNode(13);
root->right->left=newNode(14);
root->right->right=newNode(15);
root->right->left->left=newNode(21);
root->right->left->right=newNode(22);
root->right->right->right=newNode(24);
root->right->right->left=newNode(23);

wrapper(root,sum);
}
