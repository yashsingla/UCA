//time complexity:O(n)
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left,*right;
};


struct node *newNode(int n)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=n;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}



void print(struct node *root)
{
struct node *last;
    while(root!=NULL)
    {
        printf("%d\n",root->key);
        last=root;
        root=root->right;
    }

  printf("\n\nPrevious part:\n\n");
    while(last!=NULL)
    {
        printf("%d\n",last->key);
        last=last->left;
    }
}

 void wrapper(struct node *root,struct node **head)
{
         if(root==NULL)
              return;

    wrapper(root->right,head);

   root->right=(*head);

   if((*head)!=NULL)
    (*head)->left=root;

  (*head)=root;
  wrapper(root->left,head);
}


int main()
{
    struct node *root=NULL;
    struct node *head=NULL;
    root=newNode(10);
    root->left=newNode(12);
    root->right=newNode(15);
    root->left->left=newNode(25);
    root->left->right=newNode(30);
    root->right->left=newNode(36);

    wrapper(root,&head);
    print(head);
}
