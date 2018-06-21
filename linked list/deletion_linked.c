
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
//---------------------------------------------------------------------------------------

struct node *deletion(int n,struct node *head)
{
    struct node *temp=head,*temp1=NULL;

    if(head->data==n)
    {
    head=head->next;
    free(temp);
    return head;
    }

while(temp!=NULL&&temp->data!=n){
     temp1=temp;
    temp=temp->next;

}
temp1->next=temp->next;
free(temp);
return head;

};

//-----------------------------------------------------------------------------------------
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

    printf("list_traversal before deletion:");
    list_traversal(head);

     int k;

      printf("enter the number you want to delete from linked list:");
      scanf("%d",&k);



   head=deletion(k,head);

    printf("list_traversal after insertion:");
    list_traversal(head);

}

