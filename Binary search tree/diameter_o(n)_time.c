//time complexity =O(n^2);
#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node* left, *right;
};

struct node* newNode(int data);


int max(int a, int b);


int diameter(struct node *root,int *height)
{
int lh=0,rh=0,ld=0,rd=0;

if(root==NULL)
{
    *height=0;
    return 0;
}

ld=diameter(root->left,&lh);
rd=diameter(root->right,&rh);

*height=max(lh,rh)+1;


return max(lh+rh+1,max(ld,rd));

}



struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

/* returns maximum of two integers */
int max(int a, int b)

{
  return (a >= b)? a: b;
}

/* Driver program to test above functions*/
int main()
{
  int x=0;
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  printf("Diameter of the given binary tree is %d\n", diameter(root,&x));

  getchar();
  return 0;
}
