#include<stdio.h>

struct node{

int key;
struct node *left,*right;

};

struct node *newNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;

return temp;
};

struct node *insert(struct node *node,int key)
{
    if(node==NULL)
    node=newNode(key);

    if(key<node->key)
        node->left=insert(node->left,key);
    else
        if(key>node->key)
        node->right=insert(node->right,key);

    return node;
};

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\n",root->key);
        inorder(root->right);
    }
}

void delete_max(struct node *r)
{   struct node *temp;
    while(r->right!=NULL)
    {  temp=r;
        r=r->right;
    }
    temp->right=NULL;
    free(temp->right);
};


int main()
{
struct node *srch;
struct node *root=NULL;
root=insert(root,50);
insert(root,30);
insert(root,20);
insert(root,40);
insert(root,60);
insert(root,70);
insert(root,80);


printf("inorder traversal:");
inorder(root);


printf("\n\n Delete Maximum Value:\n\n");

delete_max(root);

printf("inorder traversal:\n");
inorder(root);


}


