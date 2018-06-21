//Time Complexity : O(n)
//Auxiliary Space : O(n)
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

void printMax(struct node *root)
{
    queue<node*>q;
    int result=0,sum;
    q.push(root);

    while(!q.empty())
    {
        int cnt=q.size();
        sum=0;

        while(cnt--)
        {
            struct node *temp=q.front();
            q.pop();
            sum+=temp->key;

            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);

        }
        if(sum>result)
            result=sum;
    }
cout<<"result:"<<result;
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
    printMax(root);
}
