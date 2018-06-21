#include<stdio.h>

struct node{

int key;
struct node *left,*right;

};

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

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\n",root->key);
        inorder(root->right);
    }
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int max_path_sum(struct node *node,int *res)
{
    if(node==NULL)
        return 0;

    int l=max_path_sum(node->left,res);
    int r=max_path_sum(node->right,res);

    int max_sum=max(max(l,r)+node->key,node->key);
    int max_top=max(max_sum,l+r+node->key);

    *res=max(max_top, *res);

    return max_sum;
}

int max_sum(struct node *node)
{
    int max=0;
    max_path_sum(node,&max);
    return max;
}

int main()
{
struct node *root=NULL;
root=insert(root,50);
insert(root,30);
insert(root,20);
insert(root,40);
insert(root,60);
insert(root,70);
insert(root,80);
insert(root,90);

printf("inorder traversal:");
inorder(root);
int x;
printf("\n Maximum path:");
 x=max_sum(root);
printf("%d",x);

}
/*max_single is the value that would be returned to the parent calling function and max_top refers to the answer for the subtree
 within the current node.That is why we relax res with max_top. since there can be a path in the subtree of a node combining the
  left and right paths below it that are max paths.
Why do we not return max_top ?
Suppose the max_top is path consisting of left and right paths under that node.Then if we return this value then a path for some
 node above to whose calling function it is returned may lead to a splitting of path which is not desirable.
Hence we return max_single and not max_top.
However we need it since answer can be obtained from the combination of left and right paths.


1) first of all we need to have a unbreakable path...path without joints
2) for every subtree we have a maximum sum path(represented by max_top which in real is main ans for the ques )
and a maximum path (represented by max_single)

3) we return max_single because we need to construct max_path_sum from then but if we return maxtop of a subtree then it may
have the max_path_sum but may break the path by having a joint  but condition is we need to have disjoint path

4) ultimately the ans is max_top when root node is returned as it is made from all maximum paths .
*/

