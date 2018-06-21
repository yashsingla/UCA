/*
ALGORITHM:
1) we traverse the array from right to left and keep inserting elements into BST
2) for each element inserted we  replace it in the array by its inorder successor in BST
3) if element inserted is max so far we replace it by -1 in the array
*/

/*
Worst case time complexity of above solution is also O(n2) as it uses BST. The worst case will happen when array is sorted in
ascending or descending order. The complexity can easily be reduced to O(nlogn) by using balanced trees like red-black trees.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *newNode(int n)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->left=NULL;
    temp->right=NULL;
    temp->key=n;

     return temp;
};

struct node *insert(int n,struct node *root,int *succ)
{
    if(root==NULL)
        return newNode(n);

    if(n<root->key)
    {
        *succ=root->key;
        root->left=insert(n,root->left,succ);
    }
    else
        if(n>root->key)
    {
        root->right=insert(n,root->right,succ);
    }
};


void fun(int a[],int n)
{
    int i;
    struct node *root=NULL;

     for(i=n-1;i>=0;i--)
   {
       int succ=-1;

       if(i==n-1)
       root=insert(a[i],root,&succ);

       else

       insert(a[i],root,&succ);

        a[i]=succ;
    }
}

void print(int a[],int n)
{
   int i;
   for(i=0;i<n;i++)
    printf("%d\n",a[i]);
 printf("\n\n");
}

int main()
{

    int a[]={8, 58, 71, 18, 31, 32, 63, 92,43, 3, 91, 93, 25, 80, 28};
    int n=sizeof(a)/sizeof(a[0]);

    print(a,n);
    fun(a,n);
    printf("\n\n");
    print(a,n);

}
