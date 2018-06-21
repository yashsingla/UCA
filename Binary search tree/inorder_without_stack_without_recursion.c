#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
struct node* node = (struct node*)
					malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}

void inorder(struct node *root)
{
    struct node *cur,*pre;

   if(!root)
      return;

    cur=root;

    while(cur)
    {
        if(!cur->left)
        {
            printf("%d\n",cur->data);
            cur=cur->right;
        }
        else
        {
            pre=cur->left;

            while(pre->right!=NULL&&pre->right!=cur)
                  pre=pre->right;

                  if(!pre->right)
                  {
                      pre->right=cur;
                      cur=cur->left;
                  }
                  else
                  {
                      pre->right=NULL;
                      printf("%d\n",cur->data);
                      cur=cur->right;
                  }

        }//if condn !cur->left ends

    }//outer while ends

}//function ends



/* Driver program to test size function*/
int main()
{
struct node *root = newNode(4);
root->left	 = newNode(2);
root->right	 = newNode(6);
root->left->left = newNode(1);
root->left->right = newNode(3);
root->right->right = newNode(7);
root->right->left = newNode(5);

printf("inorder:\n");
inorder(root);

getchar();
return 0;
}
