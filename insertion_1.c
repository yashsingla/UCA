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
/*
struct node *search(struct node *node,int key)  // iterative function for search
{
    struct node *temp=node;

    while(temp!=NULL)
    {
        if(temp->key==key)
            return temp;

        if(key<temp->key)
            temp=temp->left;
        else
            if(key>temp->key)
            temp=temp->right;
    }
    return NULL;
};
*/
struct node *search(struct node *node,int key)  // recursive function for search
{
    if(node==NULL||node->key==key)
        return node;
     if(key<node->key)
     return search(node->left,key);

    if(key>node->key)
   return search(node->right,key);
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

printf("\nSearch implemented:");
srch=search(root,90);
if(srch!=NULL)
    printf("found");
else
    printf("Not found");

}

