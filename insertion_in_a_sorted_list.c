
//using insertion at the end
#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *list_creation(struct node *head)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    temp->next=NULL;



    if(head==NULL){
        head=temp;
        return head;
    }
struct node* last=head;

    while(last->next!=NULL)
        last=last->next;
     last->next=temp;

    return head;
}

struct node *insertion_sorted(struct node *snode,struct node *head)
{    int p=0;
      struct node *temp,*head1=head;

      if(head==NULL){
        head=snode;
        head->next=NULL;
        return head;
      }

      while((snode->data)>(head1->data))
      {   p=1;
          temp=head1;
          head1=head1->next;
      }
            if(p==1){
      snode->next=head1;
      temp->next=snode;
            }
            else
            {
                snode->next=head1;
                head1=snode;
            }

      return head1;
}

void list_traversal(struct node *head)
{   struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }

}


int main()
{    int x=1;
     struct node *head= (struct node*)malloc(sizeof(struct node));
      printf("enter value for first node:");
      scanf("%d",&head->data);
      head->next=NULL;                                         // take the case where head=NULL;

    printf("list_creation function:");

    while(x>0){
   head=list_creation(head);
    printf("Do you want to enter more?");
    scanf("%d",&x);
    }

    printf("list_traversal before insertion:");
    list_traversal(head);



    struct node *snode=(struct node*)malloc(sizeof(struct node));
      printf("enter the number you want to enter in linked list:");
      scanf("%d",&snode->data);
      snode->next=NULL;

   head=insertion_sorted(snode,head);

    printf("list_traversal after insertion:");
    list_traversal(head);

}
