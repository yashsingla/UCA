#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int left[n1],right[n2],i,j,k;

    for(i=0;i<n1;i++)
        left[i]=a[i+l];

    for(i=0;i<n2;i++)
        right[i]=a[m+i+1];

    i=0,j=0,k=l;

    while(i<n1&&j<n2)
    {
        if(left[i]<right[j])
           a[k]=left[i++];
         else
            a[k]=right[j++];

        k++;
}

while(i<n1)
{
    a[k++]=left[i++];
}

while(j<n2)
{
    a[k++]=right[j++];
}


}


void merge_sort(int a[],int l,int r)
{
    if(l<r)
    {
     int m=(l+r)/2;
    merge_sort(a,l,m);
    merge_sort(a,m+1,r);
    merge(a,l,m,r);
    }
}

struct node{

int key;
struct node *left,*right;

};
struct node *root=NULL;

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


struct node *balanced_tree(int a[],int l,int r)
{

      if(l<=r)
     {
        int m=(l+r)/2;
        root=insert(root,a[m]);
       balanced_tree(a,l,m-1);
       balanced_tree(a,m+1,r);

}
return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {   inorder(root->left);
        printf("%d\n",root->key);

        inorder(root->right);
    }
}


int main()
{
    int a[]={6,3,1,5,2,4,7},i;
    int n=sizeof(a)/sizeof(a[0]);

     merge_sort(a,0,n-1);
  struct node *root=balanced_tree(a,0,n-1);
     printf("inorder");
     inorder(root);
   //for(i=0;i<n;i++)
    //printf("%d\n",a[i]);
}
