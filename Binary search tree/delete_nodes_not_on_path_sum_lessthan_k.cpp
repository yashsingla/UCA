//perfectly running code, my solution
#include<iostream>
using namespace std;

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *new_node(int key)
{
    struct node *temp=new node;
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

int fun(struct node *root,int sum,int k)
{
    if(!root)
        return 0;

    if((!root->left&&!root->right)&&(sum+root->key)<k)
        return 1;

    if(fun(root->left,sum+root->key,k))
    {
        struct node *temp=root->left;
        root->left=NULL;
        delete(temp);
    }

    if(fun(root->right,sum+root->key,k))
    {
        struct node *temp=root->right;
        root->left=NULL;
        delete(temp);
    }
    return 0;
}

void preorder(struct node *root)
{
    if(!root)
     return;

cout<<root->key<<" ";
    preorder(root->left);

    preorder(root->right);
}

int main()
{
    struct node *temp=new_node(1);
    temp->left=new_node(2);
    temp->left->left=new_node(4);
    temp->left->right=new_node(5);
    temp->left->left->left=new_node(8);
    temp->left->right->left=new_node(12);
    temp->left->left->right=new_node(9);
    temp->left->left->right->left=new_node(13);
    temp->left->left->right->right=new_node(14);
    temp->left->left->right->right->left=new_node(15);
    temp->right=new_node(3);
    temp->right->left=new_node(6);
    temp->right->right=new_node(7);
    temp->right->right->left=new_node(10);
    temp->right->right->left->right=new_node(11);

   preorder(temp);
    fun(temp,0,20);
    cout<<endl;
    preorder(temp);
}
