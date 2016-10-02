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

int check_validity(struct node *root,int l,int h)
{
    if(root==NULL)
        return 1;

    if((root->key<=l)||(root->key>=h))
    return 0;

   return check_validity(root->left,l,root->key)&&check_validity(root->right,root->key,h);


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

struct node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);


printf("inorder traversal:");
inorder(T);
int x;
printf("check validity: ");
 //x=check_validity(root,-1,1000);
 x=check_validity(T);   /*here l=-1 and h=100 but l can be minus infinity and r can be plus infinity*/
if(x==1)
    printf("valid");

else
    printf("Invalid");

}

