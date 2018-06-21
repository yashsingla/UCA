#include<iostream>
#include<queue>
#include<map>
#include<limits.h>

using namespace std;
struct node
{
    int key;
    int hd;
    struct node *left;
    struct node *right;
};

struct node *newNode(int key)
{
    struct node *temp=new node;
    temp->left=NULL;
    temp->right=NULL;
    temp->key=key;
    temp->hd=INT_MAX;
return temp;
};


void printBottomView(struct node *root)
{
    map<int,int>m;
    queue<struct node*>q;

    int hd;
    root->hd=0;
    q.push(root);

    while(!q.empty())
    {
        struct node *temp=q.front();
        q.pop();

        hd=temp->hd;

        m[hd]=temp->key;

        if(temp->left)
        {
            temp->left->hd=hd-1;
            q.push(temp->left);
        }

        if(temp->right)
        {
            temp->right->hd=hd+1;
            q.push(temp->right);
        }
    }

    map<int,int>::iterator it;

    for(it=m.begin();it!=m.end();it++)
        cout<<it->second<<" ";
}


int main()
{
struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

   printBottomView(root);
}
