#include<iostream>
#include<queue>
#include<stdlib.h>

using namespace std;

struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

void height(struct node *root)
{
    queue<node*>q;
    int height=0;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
        int k=0;

        while(count--)
        {
            k=1;
            struct node *temp=q.front();
            q.pop();

            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
        }
        if(k==1)
            height++;
    }
    cout<<"height:"<<height;
}

int main()
{
    struct node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->right=newNode(8);
    root->right->right->left=newNode(6);
    root->right->right->right=newNode(7);
    height(root);
}
