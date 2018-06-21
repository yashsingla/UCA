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

void rearrangeEvenOdd(struct node *head)
{
    if(head==NULL)
        return;

    struct node *odd=head;
    struct node *even=head->next;
    struct node *feven=even;

    while(1)
    {
        if(!odd||!even||!even->next)
        {
            odd->next=feven;
            break;
        }
      odd->next=even->next;
      odd=even->next;

      if(!odd->next)
      {
          even->next=NULL;
          odd->next=feven;
            break;
      }
   even->next=odd->next;
      even=odd->next;
   }
}

void print(struct node *root)
{
    while(root)
    {
        printf("%d\t",root->data);
        root=root->next;
    }
}

int main()
{

struct node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

printf("Given Linked List\n");
    print(head);

    rearrangeEvenOdd(head);

    printf("\nModified Linked List\n");
    print(head);

}
