#include<stdio.h>
#include<stdlib.h>
// red=1,black=0

struct node
{
    int key;
    struct node *left,*right;
    int color;
};

struct node *newNode(int key,int color)
{
    struct node *node=(struct node*)malloc(sizeof(node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
   node->color=color;
   return node;
};

int isRed(struct node *root)
{
    if(!root)
        return 0;
    if(root->color==1)
        return 1;
    else
        return 0;
}

struct node *rotateLeft(struct node *root)
{
    struct node *x=root;
    struct node *h=root->right;

    x->right=h->left;
    h->left=x;
    h->color=x->color;
    x->color=1;
    return h;
};

struct node *rotateRight(struct node *root)
{
    struct node *x=root;
    struct node *h=root->left;

    x->left=h->right;
    h->right=x;
    h->color=x->color;
    x->color=1;

    return h;
};


void flipColors(struct node *root)
{
    root->color=1;
    root->right->color=0;
    root->left->color=0;
}

struct node *insert(struct node *root,int key)
{
    if(!root)
    return newNode(key,1);


    if(key<root->key)
        root->left=insert(root->left,key);
    else if(key>root->key)
        root->right=insert(root->right,key);


    if(isRed(root->right)&&!isRed(root->left))
        root=rotateLeft(root);

    if(isRed(root->left)&&isRed(root->left->left))
        root=rotateRight(root);

    if(isRed(root->right)&&isRed(root->left))
        flipColors(root);

        return root;
};

void print(struct node *root)
{
     if(!root)
        return;

    printf("%d\n",root->key);
    print(root->left);

    print(root->right);
}

int main()
{

struct node *root=NULL;
root=insert(root,1);
root= insert(root,2);
root=insert(root,3);
root=insert(root,4);
root=insert(root,5);
 root=insert(root,6);

 print(root);
}
