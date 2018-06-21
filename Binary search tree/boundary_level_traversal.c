#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int key;
};

struct node *newNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->left=temp->right=NULL;
    temp->key=key;

    return temp;
};

void printLeft(struct node *root)
{
    if(!root)
        return;

    if(root->left)
    {
        printf("%d ",root->key);
        printLeft(root->left);
    }
    else
        if(root->right)
    {
        printf("%d ",root->key);
        printLeft(root->right);
    }
}

void printRight(struct node *root)
{
    if(!root)
        return;

    if(root->right)
    {
        printRight(root->right);
        printf("%d ",root->key);

    }
    else
        if(root->left)
    {
        printRight(root->left);
        printf("%d ",root->key);

    }
}

void printLeaf(struct node *root)
{
    if(!root)
        return;

  if(!root->left&&!root->right)
     printf("%d ",root->key);

    printLeaf(root->left);
    printLeaf(root->right);


}

void wrapper(struct node *root)
{
    printf("%d ",root->key);

    printLeft(root->left);
    //printf("\n");
    printLeaf(root->left);
   //printf("\n");
    printLeaf(root->right);
    //printf("\n");
    printRight(root->right);

}

int main()
{
    struct node *root=newNode(20);
    root->left=newNode(8);
    root->left->left=newNode(4);
    root->left->left->left=newNode(5);
    root->left->left->right=newNode(11);
    root->left->right=newNode(12);
    root->left->right->left=newNode(10);
    root->left->right->right=newNode(14);
    root->right=newNode(22);
    root->right->right=newNode(25);

    wrapper(root);
}
