#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
struct node* node = (struct node*)
					malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}

void count(struct node *root,int l,int h,int *c)
{
  //time complexity:O(n)
       if(!root)
        return;

    count(root->left,l,h,c);
    if(root->data>=l&&root->data<=h){

        printf("%d\n",root->data);
        (*c)++;
        }
    count(root->right,l,h,c);
}


void count1(struct node *root,int l,int h)
{
  //time complexity:O(logN+k) where k is number of nodes in range of l and h
       if(!root)
        return;

  if(root->data==l&&root->data==h)
      return 1;


    if(root->data>=l&&root->data<=h)
 return 1 + count(root->left,l,h) + count(root->right,l,h);

 else
    if(root->data<low)

  return  count(root->right,l,h);

else

  return count(root->left,l,h);


}



int main()
{
    int l=1,h=45,c=0;
struct node *root = newNode(10);
root->left	 = newNode(5);
root->right	 = newNode(50);
root->left->left = newNode(1);
//root->left->right = newNode(3);
root->right->right = newNode(100);
root->right->left = newNode(40);

count(root,l,h,&c);

printf("No. of nodes in given Range[%d,%d] is:%d",l,h,c);

getchar();
return 0;
}
