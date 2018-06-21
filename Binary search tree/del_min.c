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

void delete_min(struct node *root)
{
    while(root->left->left)
    {
        root=root->left;
    }

    if(root->left->right)
    {
        struct node *temp=root->left;
        root->left=root->left->right;
        free(temp);
    }
    else
    {
        struct node *temp=root->left;
        root->left=NULL;
        free(temp);
    }

}

int main()
{
struct node *srch;
struct node *root=NULL;
root=insert(root,90);
insert(root,600);
insert(root,30);
insert(root,40);
insert(root,50);



printf("inorder traversal:");
inorder(root);

struct node *min;
printf("\n\n Delete Minimum Value:\n");

delete_min(root);

printf("inorder traversal:");
inorder(root);


}


