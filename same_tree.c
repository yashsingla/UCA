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

int same_tree(struct node *root,struct node *root1)
{
   int x;
    if(root==NULL&&root1==NULL)
        return 1;

    if(root==NULL||root1==NULL)
             return 0;

        if(root->key!=root1->key)
                return 0;
        else
        {
            x=same_tree(root->left,root1->left);
            x=same_tree(root->right,root1->right);
        }
return x;
}


int main()
{

struct node *root=NULL;
struct node *root1=NULL;
root=insert(root,50);
insert(root,30);
insert(root,20);
insert(root,40);
insert(root,60);
insert(root,70);
insert(root,80);


printf("First tree:");
inorder(root);

root1=insert(root1,50);
insert(root1,30);
insert(root1,20);
insert(root1,40);
insert(root1,60);
insert(root1,70);
insert(root1,80);



printf("second tree:\n");
inorder(root1);

if(same_tree(root,root1))
printf("yes");
else
printf("NO");

}



