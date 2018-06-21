// another solution is to find minimum of right-subtree and maximum of lft subtree of every node,if mini in right is greater than current node and
// maximum in left is smaller than the current node then return true ,check this for every node..time: O(n^2), space: O(n)
#include<iostream>
#include<limits.h>
using namespace std;

struct node
{
    int key;
    struct node *left,*right;
};

struct node *new_node(int key)
{
    struct node *temp=new node;
    temp->left=temp->right=NULL;
    temp->key=key;
    return temp;
};

//solution -1, time and space complexity: O(n);
// here we are traversing in inorder fashion , with a prev variable containing last node visited so, if last node visited i.e if prev is greater than
// current node then return 0
int bst_1(struct node *root, int *prev)
{
    if(!root)
        return 1;

    int x=bst_1(root->left,prev);

    if(root->key<(*prev))
        return 0;

     (*prev) = root->key;

    int y=bst_1(root->right,prev);

   return x&&y;
}

// time and space : O(n)
int bst_2(struct node *root, int mini, int maxi)
{
    if(!root)
        return 1;

    //if(!root->left&&!root->right)
      //  return 1;
  if( root->key>mini &&
      root->key<maxi&&
      bst_2(root->left,mini,root->key) &&
      bst_2(root->right,root->key,maxi)
    );
        return 1;
return 0;
}


void wrapper(struct node *root)
{
    /*
    int prev=INT_MIN;
    if(bst_1(root,&prev)) // working fine
        cout<<"is a BST";
    else
        cout<<"not a BST";
*/
  int mini=INT_MIN, maxi=INT_MAX;
        if(bst_2(root,mini,maxi)) // not working proper but algorithm is correct
        cout<<"is a BST";
    else
        cout<<"not a BST";
}

int main()
{
    struct node *root=new_node(6);
    root->left=new_node(2);
    root->right=new_node(8);
    root->left->left=new_node(1);
    root->left->right=new_node(9);
   // root->right->left->right=new_node(7);
   // root->right->left->right->left=new_node(6);
    wrapper(root);
}
