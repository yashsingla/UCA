#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next,*prev;
};


void insertion_begin(struct node **head,int n)
{
    struct node *temp=(struct node *)malloc(sizeof(temp));
    temp->key=n;
    temp->prev=NULL;
    temp->next=(*head);

    if((*head)!=NULL)
    (*head)->prev=temp;

    *head=temp;
}

void insert_after(struct node *node,int n)
{
   struct node *temp=(struct node *)malloc(sizeof(temp));
    temp->key=n;

     temp->next=node->next;
     temp->prev=node;

     node->next=temp;

     if(temp->next)
     temp->next->prev=temp;

}

void insert_before(struct node *node,int n)
{
   struct node *temp=(struct node *)malloc(sizeof(temp));
    temp->key=n;

     temp->prev=node->prev;
     temp->next=node;

     node->prev=temp;

     if(temp->prev)
     temp->prev->next=temp;

}


void print(struct node *root)
{
struct node *last;
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

int main()
{
struct node *node=NULL;

insertion_begin(&node,5);
insertion_begin(&node,4);
insertion_begin(&node,3);
insertion_begin(&node,2);
insertion_begin(&node,1);

printf("Insertion Beginning:\n\n");
print(node);

insert_after(node->next->next,6);

printf("Inserting after given node:\n\n");
print(node);

insert_before(node->next->next,7);

printf("Inserting before given node:\n\n");
print(node);



}

