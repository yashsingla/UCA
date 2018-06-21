#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

void detect_loop(struct node *head)
{
    struct node *slow=head;
    struct node *fast=head->next;
    struct node *fast1=NULL;

    while(fast&&fast->next)
    {
        if(slow==fast)
            break;

        slow=slow->next;
         fast=fast->next->next;}

     if(slow==fast)
    { printf("loop present ,now removing loop");
        slow=head;
        while(slow!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
     fast->next=NULL;
    }
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("\n%d  ", node->data);
        node = node->next;
    }
}

struct node *newNode(int key)
{
    struct node *temp =(struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

/* Drier program to test above function*/
int main()
{
    struct node *head = newNode(1);
    struct node *sing=head;
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
   head->next->next->next->next = sing->next->next->next;
  // printList(head);

detect_loop(head);

printList(head);
return 0;
}
