//Time Complexity: Time complexity of the above solution is O(n). The tree is traversed twice, and then path arrays are compared.

#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

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

bool LCA_Tree(struct node *root,int n,vector<int>&v)
{
    if(!root)
        return false;

    v.push_back(root->key);

    if(root->key==n)
       return true;


if(LCA_Tree(root->left,n,v)||LCA_Tree(root->right,n,v))
          return true;

   v.pop_back();
   return false;
}

int wrapper(struct node *root,int n1,int n2)
{
    vector<int>v1;
    vector<int>v2;

 if(!(LCA_Tree(root,n1,v1))||!(LCA_Tree(root,n2,v2)))
        return -1;
//LCA_Tree(root,n1,v1); statement 1
//LCA_Tree(root,n2,v2);  statement 2

 int k1=v1.size();
 int k2=v2.size();

//if(k1==0||k2==0)
  //  return -1;  by using statement 1 and 2,this is also correct

 int i,p,j;

    for(i=0;i<k1&&i<k2;i++)
        if(v1[i]!=v2[i])
        break;

 //printf("Least Common factor of %d and %d:%d",n1,n2,v1[i-1]);
return v1[i-1];
}

int main()
{
struct node *root=newNode(1);
root->left=newNode(3);
root->left->left=newNode(2);
root->left->right=newNode(11);
root->right=newNode(14);
root->right->left=newNode(4);
root->right->right=newNode(5);
root->right->left->left=newNode(10);
root->right->left->right=newNode(2);
root->right->right->right=newNode(6);
int n1=10,n2=6;
cout<<"lca:"<<wrapper(root,n1,n2);
}
