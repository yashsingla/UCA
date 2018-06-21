#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next;
};

struct node *createNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->next=NULL;
    temp->key=key;
    return temp;
};

struct node *XOR(struct node *a,struct node *b)
{
return (struct node*)((unsigned int)(a)^(unsigned int)(b));
};



void insert(int key,struct node **head)
{
if((*head)==NULL)
    {
        (*head)=createNode(key);
        return;
    }

    struct node *temp=createNode(key);
    temp->next=(*head);
    (*head)=temp;
}

void print(struct node *head)
{
    while(head)
    {
        printf("%d ",head->key);
        head=head->next;
    }
}

void singlyToDoubly(struct node *head)
{
      struct node *temp=head;
      struct node *temp2=NULL,*temp3=NULL;

      while(temp)
      {
          temp2=temp->next;
          temp->next=XOR(temp3,temp2);

          temp3=temp;
          temp=temp2;
      }
}

void print1(struct node *head)
{
  // following code for printing left to right

   struct node *temp=head;
    struct node *temp1=head->next;
   struct node *temp2=NULL;

    while(temp1)
    {
        printf("%d ",temp->key);

        temp2=temp;
        temp=temp1;
        temp1=XOR(temp2,temp1->next);
    }
    printf("%d\n\n",temp->key);
// following code for printing right to left
     temp1=temp2;
     temp2=NULL;

    while(temp1)
    {
        printf("%d ",temp->key);
        temp2=temp;
        temp=temp1;
        temp1=XOR(temp2,temp1->next);
    }
    printf("%d ",temp->key);
}

int main()
{
    struct node *head=NULL;
    struct node *head1;

    insert(1,&head);
    head1=head;
    insert(2,&head);
    insert(3,&head);

printf("singly linked list:\n");
  print(head);


   singlyToDoubly(head);

 printf("\n\nafter conversion to doubly linked list:\n");
  print1(head);
}
