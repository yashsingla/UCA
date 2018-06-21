#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left,*right;
};

struct list
{
    int key;
   struct list *prev,*next;
};
struct list *t=NULL;

struct node *newNode(int n)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=n;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}


void convert(struct list **head,int n)
{  struct list *last=(*head);
    struct list *temp=(struct node *)malloc(sizeof(temp));
    temp->key=n;
    temp->next=NULL;

    if((*head)==NULL)
    {
        temp->prev=NULL;
        *head=temp;
        return;
    }


    while(last->next!=NULL)
      last=last->next;

last->next=temp;
    temp->prev=last;

 // return;
   *head=temp;
}


void print(struct list *root)
{
struct list *last;
    while(root!=NULL)
    {
        printf("%d\n",root->key);
        last=root;
        root=root->next;
    }

  printf("\n\nPrevious part:\n\n");
    while(last!=NULL)
    {
        printf("%d\n",last->key);
        last=last->prev;
    }
}

 void wrapper(struct node *root)
{
    if(root==NULL)
        return;

    wrapper(root->left);
    convert(&t,root->key);
    wrapper(root->right);
}

void making_circular(struct list *root)
{
     struct list *last=root;
     while(last->next)
        last=last->next;

     last->next=root;
     root->prev=last;
}

void print_circular(struct list *root)
{
      printf("%d\n",root->key);
     struct list *last=root->next;
     while(last!=root)
     {
         printf("%d\n",last->key);
         last=last->next;
     }
}


int main()
{
    struct node *root=NULL;
    root=newNode(10);
    root->left=newNode(12);
    root->right=newNode(15);
    root->left->left=newNode(25);
    root->left->right=newNode(30);
    root->right->left=newNode(36);
    struct node *t=NULL:
    wrapper(root);
    making_circular(t);
    print_circular(t);
    //print(t);
}
