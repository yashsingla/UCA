#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key,size;
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
   node->size=1;
   return node;
};

int size(struct node *root)
{
    if(!root)
        return 0;

    return root->size;
}
/*
int size(struct node *root)
{
    if(!root)
        return 0;

    return size(root->left)+size(root->right)+1;
}
*/

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

    x->size=size(x->left)+size(x->right)+1;
    h->size=size(h->left)+size(h->right)+1;

   // x->size=size(x);
    // h->size=size(h);

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
    x->size=size(x->left)+size(x->right)+1;
    h->size=size(h->left)+size(h->right)+1;
    //x->size=size(x);
    //h->size=size(h);
    return h;
};


void flipColors(struct node *root)
{
    root->color=1;
    root->right->color=0;
    root->left->color=0;

}


struct node *insert(int key,struct node *root,int *result)
{
    if(!root)
    return newNode(key,1);


    if(key<root->key){
        root->left=insert(key,root->left,result);

       (*result)=(*result)+(size(root->right))+1;
    }
    else if(key>root->key)
        root->right=insert(key,root->right,result);

root->size=size(root->left)+size(root->right)+1;

    //root->size=size(root);

    if(isRed(root->right)&&!isRed(root->left))
        root=rotateLeft(root);

    if(isRed(root->left)&&isRed(root->left->left))
        root=rotateRight(root);

    if(isRed(root->right)&&isRed(root->left))
        flipColors(root);

        return root;
};

int count_inversion(int a[],int n)
{
    int result=0;
    struct node *root=NULL;
    int i;
    for(i=0;i<n;i++)
    root=insert(a[i],root,&result);
    return result;
}


int main()
{
    int a[]={8,4,2,1};
    int n=sizeof(a)/sizeof(a[0]);

  int x=count_inversion(a,n);
  printf("count inversion:%d",x);
}
