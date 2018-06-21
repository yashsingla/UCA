//time complexity:O(NlogN)
#include<stdio.h>
#include<stdlib.h>
//#include<algorithm.h>

int cmp(const void *a,const void *b)
{
    int x= *(int*)a;
    int y= *(int *)b;

    return x-y>0;
}

struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int key)
{
    struct node *temp=(struct  node*)malloc(sizeof(struct node));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
};

struct node *insert(struct node *root,int key)
{
    if(root==NULL){
    return  newNode(key);
    }

    if(key<root->key)
        root->left=insert(root->left,key);
    else
        root->right=insert(root->right,key);

return root;
}

void balance(int a[],int l,int r,struct node **root)
{
    if(r<l)
        return;

    int m=(l+(r-l))/2;

     if(!(*root))
    (*root)=insert(*root,a[m]);
    else
    insert(*root,a[m]);

    balance(a,l,m-1,root);
    balance(a,m+1,r,root);

}

void inorder(struct node *root)
{
    if(root==NULL)
        return;

       inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
}

void wrapper(int a[],int n)
{
   qsort(a,n,sizeof(int),cmp);

  struct node *root=NULL;

    balance(a,0,n-1,&root);

    //inorder(root);
}

int main()
{
    //int a[]={15,5,3,1,4,10,17,25,20,30};
    int a[]={10,5,1,7,40,50};
    int n=sizeof(a)/sizeof(a[0]);

    wrapper(a,n);
}
