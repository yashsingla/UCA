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

void insertion_end(struct node **head,int n)
{  struct node *last=(*head);
    struct node *temp=(struct node *)malloc(sizeof(temp));
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
struct node *node1=NULL;

/*
insertion_begin(&node,5);
insertion_begin(&node,4);
insertion_begin(&node,3);
insertion_begin(&node,2);
insertion_begin(&node,1);

printf("Insertion Beginning:\n\n");
print(node);
*/
printf("\n\nInsertion End:\n\n");
insertion_end(&node1,5);
insertion_end(&node1,4);
insertion_end(&node1,3);
insertion_end(&node1,2);
insertion_end(&node1,1);

print(node1);

getch();
return 0;
}
