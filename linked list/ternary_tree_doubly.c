#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left,*right,*middle;
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
    temp->middle=NULL;
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

  return;
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
    convert(&t,root->key);
    wrapper(root->left);
    wrapper(root->middle);
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
{     printf("%d\n",root->key);
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
    root = newNode(30);

    root->left = newNode(5);
    root->middle = newNode(11);
    root->right = newNode(63);

    root->left->left = newNode(1);
    root->left->middle = newNode(4);
    root->left->right = newNode(8);

    root->middle->left = newNode(6);
    root->middle->middle = newNode(7);
    root->middle->right = newNode(15);

    root->right->left = newNode(31);
    root->right->middle = newNode(55);
    root->right->right = newNode(65);

    wrapper(root);
    making_circular(t);
    print_circular(t);
    //print(t);
}


