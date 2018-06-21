#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next;
};

struct node *newNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->key=key;
    return temp;
};

void print(struct node *root)
{
    while(root)
    {
        printf("%d ",root->key);
        root=root->next;
    }
}

struct node *reverse(struct node *root)
{
    struct node *prev=NULL,*temp=root,*temp1=NULL;

    while(temp)
    {
        temp1=temp->next;
        temp->next=prev;
        prev=temp;
        temp=temp1;
    }

    return prev;
};

void fun(struct node *root)
{
    if(!root)
        return;

     struct node *head1=root;
    struct node *mid=root;
    struct node *mid1=root->next;

    while(mid&&mid->next&&mid1&&mid1->next)
    {
        mid=mid->next;
        mid1=mid1->next->next;
    }

    mid1=mid->next;
    mid->next=NULL;

    struct node *head2=reverse(mid1);
    struct node *head3;

    while(head1&&head2)
    {
        head1->key=(head1->key-head2->key);
        mid1=head1;
        head1=head1->next;
        head2=head2->next;
    }
      if(head2)
    mid1->next=head2;
}

int main()
{
   struct node *temp=newNode(1);
    temp->next=newNode(2);
   temp->next->next=newNode(3);
   temp->next->next->next=newNode(4);
   temp->next->next->next->next=newNode(5);
   temp->next->next->next->next->next=newNode(6);
//temp->next->next->next->next->next->next=newNode(7);

   printf("Before modifying:");
   print(temp);

   fun(temp);

   printf("\n\nAfter modifying:");
   print(temp);
}
