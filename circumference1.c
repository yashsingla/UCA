#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int item)
{    struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->key=item;
     temp->left=NULL;
     temp->right=NULL;
     return temp;
};

struct node *insert(struct node *root,int n)
{
    if(root==NULL)
    return newNode(n);

    if(n<root->key)
        root->left=insert(root->left,n);
    else
        if(n>root->key)
      root->right=insert(root->right,n);

    return root;
};

void print_leaf(struct node *root)
{
    if(root){
    print_leaf(root->left);
    if((!root->left)&&(!root->right))
        printf("%d\n",root->key);
    print_leaf(root->right);
}
}
void print_left(struct node *root)
{
    if(root)
    {
        if(root->left)
        {
            printf("%d\n",root->key);
            print_left(root->left);
        }
        else
            if(root->right)
            {
            printf("%d\n",root->key);
            print_left(root->right);
        }
    }
}

void print_right(struct node *root)
{
    if(root)
    {
        if(root->right)                           //time_complexity:O(n);
        {
            print_right(root->right);
            printf("%d\n",root->key);

        }
        else
            if(root->left)
            {
                print_right(root->left);
            printf("%d\n",root->key);

        }
    }
}


void print_boundary(struct node *root)

{   if(root){
    printf("%d\n",root->key);
    print_left(root->left);
    print_leaf(root->left);
    print_leaf(root->right);
    print_right(root->right);
}
}

int main()
{
struct node *root         = newNode(8);
    root->left                = newNode(3);
    root->left->left          = newNode(1);
    root->left->right         = newNode(6);
root->left->right->left   = newNode(4);
    root->left->right->right  = newNode(7);
    root->right               = newNode(10);
    root->right->right        = newNode(14);
    root->right->left        = newNode(9);
    root->right->right->left        = newNode(13);
    root->right->right->right        = newNode(15);

struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);

  print_boundary(root);

}
