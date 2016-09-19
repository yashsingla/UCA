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

int i=0,j=0;
struct node *y[10];

struct node **level_order(struct node* node)
{
if(node==NULL)
    return y;

y[j]=node;

if(y[j]->left!=NULL){
    y[++i]=y[j]->left;
   //l=l+1;
}

if(y[j]->right!=NULL){
    y[++i]=y[j]->right;
    //l=l+1;
}
    j=j+1;

   level_order(y[j]);
//return y;
}


int main()
{
struct node *root=NULL;
root=insert(root,50);
insert(root,30);
insert(root,20);
insert(root,40);
insert(root,60);
insert(root,70);
insert(root,80);
insert(root,90);
insert(root,0);

printf("inorder traversal:");
inorder(root);
struct node **x;
printf("\n level order traversal:");
 x=level_order(root);
int i;

for(i=0;i<9;i++)
printf("%d\n",x[i]->key);

}



