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

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int max_path_sum(struct node *node,int *res)
{
    if(node==NULL)
        return 0;

    int l=max_path_sum(node->left,res);
    int r=max_path_sum(node->right,res);

    int max_sum=max(max(l,r)+node->key,node->key);
    int max_top=max(max_sum,l+r+node->key);

    *res=max(max_top,*res);

    return max_sum;
}

int max_sum(struct node *node)
{
    int max=0;
    max_path_sum(node,&max);
    return max;
}

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
insert(root,90);

printf("inorder traversal:");
inorder(root);
int x;
printf("\n Maximum path:");
 x=max_sum(root);
printf("%d",x);

}
