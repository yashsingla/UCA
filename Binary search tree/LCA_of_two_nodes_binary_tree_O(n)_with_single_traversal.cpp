//Time Complexity: Time complexity of the above solution is O(n). The tree is traversed here once instead of twice

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

//here in this function it is assumed that both n1 and n2 are always present..corner cases are not covered
//If one key is present and other is absent, then it returns the present key as LCA (Ideally should have returned NULL).
/*struct node *wrapper(struct node *root,int n1,int n2)
{
    if(!root)
    return NULL;

    if(root->key==n1||root->key==n2)
        return root;

    struct node *left_lca=wrapper(root->left,n1,n2);
    struct node *right_lca=wrapper(root->right,n1,n2);

    if(left_lca&&right_lca)
        return root;

    return left_lca!=NULL?left_lca:right_lca;
}
*/

struct node *LCA(struct node *root,int n1,int n2,bool v1,bool v2)
{
    if(!root)
    return NULL;

  if(root->key==n1)
  {
      v1=true;
      return root;
  }

  if(root->key==n2)
  {
      v2=true;
      return root;
  }

  struct node *left=LCA(root->left,n1,n2,v1,v2);
  struct node *right=LCA(root->right,n1,n2,v1,v2);

  if(left&&right)
    return root;

 return left!=NULL?left:right;
}

bool findd(struct node *root,int k)
{
       if(!root)
        return false;

      if(root->key==k||findd(root->left,k)||findd(root->right,k))
           return true;

      return false;
}

struct node *wrapper(struct node *root,int n1,int n2)
{
    bool v1=false,v2=false;

    struct node *lca=LCA(root,n1,n2,v1,v2);

    if(v1&&v2||(v1&&findd(lca,n2))||(v2&&findd(lca,n1)))
        return lca;

    return NULL;
};

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
//int n1=10,n2=16;
int n1=10,n2=6;

struct node *root1=wrapper(root,n1,n2);

if(root1)
cout<<"lca:"<<root1->key;
else
cout<<"lca is not present";
}
