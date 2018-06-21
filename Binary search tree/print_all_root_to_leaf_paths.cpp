#include<iostream>
#include<vector>

using namespace std;

struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int key)
{
    struct node *temp=new node;
    temp->left=NULL;
    temp->right=NULL;
    temp->key=key;
    return temp;
};

void wrapper(struct node *root,vector<int>&v)
{
    if(!root)
      return;

     v.push_back(root->key);

     if(!root->left&&!root->right)
     {
       int i;
     for(i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
     }

     wrapper(root->left,v);
     wrapper(root->right,v);

     v.pop_back();
}

int main()
{
    struct node *root=newNode(10);
    root->left=newNode(8);
    root->left->left=newNode(3);
    root->left->right=newNode(5);
    root->right=newNode(2);
    root->right->left=newNode(2);
    vector<int>v;
    wrapper(root,v);
}
