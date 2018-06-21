//time complexity:O(N)
//space complexity:O(N)

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
// elements in right view are last element of every level..in level order traversal
void printRight(struct node *root,int level,int *maxi)
{
    if(!root)
        return;

    if(*maxi<level)
    {
        cout<<root->key<<" ";
        *maxi=level;
    }

    printRight(root->left,level+1,maxi);
    printRight(root->right,level+1,maxi);
}

void printRightView(struct node *root)
{
    int maxi=0;

    printRight(root,1,&maxi);

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

   printRightView(root);
}



