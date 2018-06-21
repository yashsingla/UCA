#include<stdio.h>

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

void inorder(struct node *node)
{
    if(node){
    inorder(node->left);
    printf("%d\n",node->key);
    inorder(node->right);
    }

}
/*
we use postorder As in Postorder we check the children 1st,now suppose if any of the child of node having path more than k
 and then u don't have to remove the node,,but in Preorder u removing node first(parent),which out checking if any
of the child has path more than k,which is not look like logical,Hope it helps :)

*/

struct node *remove_node(struct node *node,int level,int k)
{
    if(node==NULL)
        return NULL;

node->left=remove_node(node->left,level+1,k);
node->right=remove_node(node->right,level+1,k);

if(node->left==NULL&&node->right==NULL&&level<k)
{
    node=NULL;
    free(node);

}
return node;

};

int main()
{ int k=4;
struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(7);
    root->right->right = newNode(6);
    root->right->right->left = newNode(8);
   printf("Before Removal:");
   inorder(root);

  struct node *root1=remove_node(root,1,k);

  printf("After Removal:");
   inorder(root1);

}
