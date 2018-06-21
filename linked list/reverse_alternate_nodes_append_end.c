#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};


struct node* newNode(int key)
{
   struct  node *temp = (struct node*)malloc(sizeof(temp));;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

struct node *reverse(struct node *head)
{
     struct node *temp1=head;
    struct node *temp2=NULL;
    struct node *temp3=NULL;

    while(temp1)
    {
        temp3=temp1->next;
        temp1->next=temp2;
        temp2=temp1;
        temp1=temp3;
    }
return temp2;
};

void fun(struct node *head)
{
   struct node *odd=head;
   struct node *even=head->next;
   struct node *feven=even;

   while(1)
   {
       if(!odd||!even||!even->next)
       {
           odd->next=reverse(feven);
           break;
       }
       odd->next=even->next;
       odd=even->next;

       if(!odd->next)
       {
           even->next=NULL;
           odd->next=reverse(feven);
           break;
       }
       even->next=odd->next;
       even=odd->next;
   }
}

void print(struct node *root)
{
    struct node *temp=root;
    while(temp)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}



int main()
{
struct node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

fun(head);
print(head);
}
