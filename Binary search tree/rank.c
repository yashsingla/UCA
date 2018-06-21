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

/* Computes the number of nodes in a tree. */
int size(struct node* node)
{
if (node==NULL)
	return 0;

    int a=1+size(node->left);
    int b=1+size(node->right);

    return a+b-1;

}

int rank_of(struct node *tree, int val) {
  int rank = 0;
  while (tree) {
    if (val < tree->data) // move to left subtree
      tree = tree->left;
    else if (val > tree->data) {
      rank += 1 + size(tree->left);
      tree = tree->right;
    }
    else
      return rank + size(tree->left);
  }
  return -1; // not found
}


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
printf("rank of %d is %d",6,rank_of(root,6));
//printf("Size of the tree is %d", size(root));

getchar();
return 0;
}
