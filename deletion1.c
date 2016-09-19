#include<stdio.h>

struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int n)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->key=n;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
};

struct node *insert(struct node *node,int n)
{
    if(node==NULL)
       node=newNode(n);

    if(n<node->key)
        node->left=insert(node->left,n);
    else
        if(n>node->key)
        node->right=insert(node->right,n);

        return node;

};

void inorder(struct node *root)
{
    if(root==NULL)
        return root;

    inorder(root->left);
    printf("%d\n",root->key);
    inorder(root->right);
}

struct node *findMin(struct node *node)
{
    struct node *temp=node;

    while(temp->left!=NULL)
        temp=temp->left;

    return temp;
};

struct node *dlt(struct node *node,int n)
{

 if(node==NULL)
 return node;

   if(n<node->key)
    node->left=dlt(node->left,n);
 else
    if(n>node->key)
    node->right=dlt(node->right,n);
 else{//main else starts

     if(node->left==NULL&&node->right==NULL)  //case for 0 child
     {
          node=NULL; // because node is a dangling pointer we have to make it null otherwise program stops working(important)
         free(node);

     }
     else
        if(node->left==NULL)    //case for 1 child
     {
         struct node *temp=node->right;
         node=NULL;
         free(node);
         return temp;
     }
     else
        if(node->right==NULL)   //case for 1 child
     {
         struct node *temp=node->left;
         node=NULL;
         free(node);
         return temp;
     }
     else{  //case for 2 child
            struct node *temp=findMin(node->right);
            node->key=temp->key;
            node->right=dlt(node->right,temp->key);
         }


 }//main else ends
return node;
}

int main()
{
    struct node *root=NULL;
struct node *node1;
root=insert(root,50);
insert(root,30);
insert(root,70);
insert(root,40);
insert(root,20);
insert(root,60);
insert(root,80);
printf("before deletion");
inorder(root);
node1=dlt(root,50);

printf("After deletion");
inorder(node1);

}
