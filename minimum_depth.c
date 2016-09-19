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

int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

/*
int min_depth(struct node* node)
{                                         //here complete tree is traversed ..little inefficiebt code

    if(node==NULL)
        return 0;

   int a=min_depth(node->left);
   int b=min_depth(node->right);

   return 1 + min(a,b);
}
*/

int i=0,j=0;
struct node *y[10];

int min_depth(struct node* node,int count_l,int count_r)
{
if(node->left==NULL&&node->right==NULL)
  return min(count_l,count_r);                                   /*efficient code to find minimum depth*/

y[j]=node;

if(y[j]->left!=NULL){
    count_l++;
    y[++i]=y[j]->left;
}
//else
  //  return count_l;

if(y[j]->right!=NULL){
    count_r++;
    y[++i]=y[j]->right;
}
//else
//return count_r;
    j=j+1;

min_depth(y[j],count_l,count_r);

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
insert(root,0);
insert(root,90);
insert(root,110);

printf("inorder traversal:");
inorder(root);
int x;
printf("\n Minimum depth:");
 x=min_depth(root,0,0);
printf("%d",x);

}



