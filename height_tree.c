#include<stdio.h>

struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int n)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->key=n;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
};

struct node *insert(struct node *node,int n)
{
    if(node==NULL)
       node=newNode(n);

    if(n<node->key)
        node->left=insert(node->left,n);
    else
        if(n>node->key)
        node->right=insert(node->right,n);

        return node;

};

void inorder(struct node *root)
{
    if(root==NULL)
        return root;

    inorder(root->left);
    printf("%d\n",root->key);
    inorder(root->right);
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int height(struct node *root)
{ int a=0,b=0;
    if(root==NULL)
        return 0;

        a=height(root->left);
        b=height(root->right);

    return (1+ max(a,b));
};

int main()
{
    struct node *root=NULL;
struct node *node1;

root=insert(root,50);
insert(root,30);
insert(root,70);
insert(root,40);
insert(root,20);
insert(root,60);
insert(root,80);
insert(root,10);
insert(root,90);
insert(root,110);
insert(root,120);
printf("inorder traversal");
inorder(root);

int x=height(root);
printf("\n\nheight:%d",x);

}

