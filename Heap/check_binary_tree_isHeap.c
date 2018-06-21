// another solution is by using queue and doing level order traversal and count number of nodes at each level,if no. of nodes
// at any level except last level is < 2 power(n)||rott->key is less then child then return false.
#include<iostream>
using namespace std;

struct node
{
    int key;
    struct node  *left;
    struct node *right;
};

struct node *new_node(int key)
{
    struct node *temp=new node;
    temp->left=NULL;
    temp->right=NULL;
    temp->key=key;
    return temp;
};

int maxi(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int height(struct node *root)
{
    if(!root)
        return 0;

    return 1+maxi(height(root->left),height(root->right));
}

int check(struct node *root,int h)
{
    if(!root)
        return 1;
    if(h>2&&(!root->left||!root->right))
        return 0;

    if(!root->left&&!root->right)
       return 1;

    if(root->left&&((root->key)>(root->left->key))&&(root->right&&(root->key)>(root->right->key)))
    return  check(root->left,h-1)&&check(root->right,h-1);
    else
        return 0;
}

void check_util(struct node  *root)
{
    int h=height(root);

    if(check(root,h))
        cout<<"binary tree is heap";
    else
        cout<<"binary tree is not a heap";
}

int main()
{
    struct node *root=new_node(97);
    root->left=new_node(46);
    root->right=new_node(37);
    root->left->left=new_node(12);
    root->right->left=new_node(7);
     //root->right->right=new_node(31);
    root->left->right=new_node(4);
  root->left->right->right=new_node(3);
   root->left->right->left=new_node(2);

   check_util(root);
}
