//solved using BST,Time complexity:O(NKlogK)
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *newNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

struct node *insert(struct node *root,int key,int *p)
{
    if(!root){
     (*p)=(*p)+1;
        return newNode(key);

    }
if(key==root->key)
    return root;
    else
    if(key<root->key)
        root->left=insert(root->left,key,p);
    else
    if(key>root->key)
        root->right=insert(root->right,key,p);

return root;
};

void inorder(struct node *root)
{
    if(!root)
        return;
    inorder(root->left);
    printf("%d",root->key);
    inorder(root->right);
}

void fun(int arr[],int k,int n)
{
int i,j;

for(i=0;i<(n-k+1);i++)
{
    int p=0;
    struct node *root=NULL;
    root=insert(root,arr[i],&p);
    for(j=i+1;j<i+k;j++)
    {
      insert(root,arr[j],&p);
    }
    //inorder(root);
    //printf("\n");
    printf("%d\n",p);
}

}

int main()
{
    int arr[]={1,2,1,3,4,2,3};
    int k=4;
    int n=sizeof(arr)/sizeof(arr[0]);

    fun(arr,k,n);
}
