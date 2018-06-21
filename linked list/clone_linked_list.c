#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next;
    struct node *arbit;
};

struct node *new_node(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=key;
    temp->next=NULL;
    temp->arbit=NULL;

    return temp;
};

void print(struct node *head)
{
    struct node *temp=head;

    while(temp)
    {
        printf("%d\t",temp->arbit->key);
        temp=temp->next;
    }
    printf("\n");
}

void new_list(struct node *head)
{
    struct node *head3=head;
    struct node *head1=new_node(head3->key);

    head3=head3->next;
    struct node *head2=head1;

    while(head3)
    {
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=head3->key;
    temp->next=NULL;
    temp->arbit=NULL;
    head2->next=temp;
    head2=temp;
    head3=head3->next;
    }

    head2=head;
    struct node *a[5];

    while(head2)
    {
        a[head2->key]=head2->next;
        head2=head2->next;
    }

    head2=head;
    head3=head1;

    while(head2)
    {
        struct node *temp1=head2->next;
        head2->next=head3;
        head3->arbit=head2;
        head2=temp1;
        head3=head3->next;
    }

    head3=head1;

    while(head3)
    {
        head3->arbit=head3->arbit->arbit->next;
        head3=head3->next;
    }

    head2=head;

   while(a[head2->key])
   {
       head2->next=a[head2->key];
       head2=head2->next;
   }
   head2->next=NULL;

  print(head);
  print(head1);
}

void create_clone(struct node *head)
{
   struct node *temp=head;
   struct node *head1=NULL;

     new_list(head);
}

int main()
{
struct node *head=new_node(1);
head->next=new_node(2);
head->next->next=new_node(3);

head->arbit=head->next->next;
head->next->arbit=head;
head->next->next->arbit=head->next;

create_clone(head);

//print(head);
}
