//At first look the time complexity looks more than O(n) but if we take a closer look,
// we can observe that no node is traversed more than twice.Therefore the time complexity is O(n).

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

void fun(struct node *root,int k)
{
      if(!root||k<0)
        return;

      if(k==0){
        printf("%d, ",root->key);
      return;
      }
        fun(root->left,k-1);
        fun(root->right,k-1);
}

int wrapper(struct node *root,int k,struct node *target)
{
            if(!root)
              return -1;

            if(root==target)
            {
                fun(root,k);
                return 0;
            }

    int  dl=wrapper(root->left,k,target);

     if(dl!=-1)
     {
         if(dl+1==k)
            printf("%d, ",root->key);
         else
            fun(root->right,k-dl-2);
         return dl+1;
     }


     int  dr=wrapper(root->right,k,target);

    if(dr!=-1)
     {
         if(dr+1==k)
            printf("%d, ",root->key);
         else
            fun(root->left,k-dr-2);
         return dr+1;
     }

     return -1;
}


int main()
{
int key=-1;
int k=2;
/*struct node *root=newNode(1);
root->left=newNode(3);
root->left->left=newNode(2);
root->left->right=newNode(1);
root->right=newNode(-1);
root->right->left=newNode(4);
root->right->right=newNode(5);
root->right->left->left=newNode(1);
root->right->left->right=newNode(2);
root->right->right->right=newNode(6);
struct node *target=root->right;*/

struct node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

struct node *target = root->left->right;

wrapper(root,k,target);
}
