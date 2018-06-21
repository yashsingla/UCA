/*Time complexity: The code first traverses down to the leftmost node which takes O(logN) time, then traverses k elements in
O(k) time. Therefore overall time complexity is O(logN + k).

>>ALGORITHM:inoder traversal for kth smallest and reverse inorder traversal for kth largest

*/

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

int kth_smallest(struct node *root,int k,int *i)
{
    if(root==NULL||i>=k)
      return;

    kth_smallest(root->left,k,i);
     (*i)++;
    if((*i)==k)
   // printf("%d",root->data);
    return(root->data);

    kth_smallest(root->right,k,i);
}

int kth_smallest_UsingMorris(struct node *root,int k)
{
struct node *cur,*pre;
int count=0;
   if(!root)
      return;

    cur=root;

    while(cur)
    {
        if(!cur->left)
        {
            count++;
            if(count==k)
                return cur->data;

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
                     count++;
            if(count==k)
                return cur->data;

                      cur=cur->right;
                  }

        }//if condn !cur->left ends

    }//outer while ends

}//function ends



/* Driver program to test size function*/
int main()
{int k=4,i=0;
struct node *root = newNode(4);
root->left	 = newNode(2);
root->right	 = newNode(6);
root->left->left = newNode(1);
root->left->right = newNode(3);
root->right->right = newNode(7);
root->right->left = newNode(5);
//kth_smallest(root,k,i);
//printf("kth smallest element is %d",kth_smallest(root,k,&i));
printf("kth smallest element is %d",kth_smallest_UsingMorris(root,k));
getchar();
return 0;
}

