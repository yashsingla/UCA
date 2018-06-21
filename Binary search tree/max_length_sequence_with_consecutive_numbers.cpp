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

void fun(struct node *root,int *p,vector<int>&v)
{
      if(!root)
        return;

      v.push_back(root->key);

      fun(root->left,p,v);
      fun(root->right,p,v);

      int i,maxi=0;
      for(i=v.size()-1;i>=0;i--)
      {
          if(v[i]==(v[i-1]+1))
            maxi++;
      } maxi++;

       if(maxi>(*p))
        (*p)=maxi;

   v.pop_back();
}

void wrapper(struct node *root)
{
    vector<int>v;
    int p=0;
    fun(root,&p,v);
   printf("Max:%d",p);
}

int main()
{
struct node *root=newNode(0);
root->left=newNode(1);
root->left->left=newNode(2);
root->left->left->left=newNode(5);
root->left->left->right=newNode(3);
root->left->left->right->left=newNode(99);
root->right=newNode(66);
root->right->right=newNode(67);
root->right->right->left=newNode(68);
root->right->right->left->right=newNode(100);

wrapper(root);
}
