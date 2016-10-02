#include <stdio.h>
#include <stdlib.h>

// A nexted list node
struct node
{
    int data;
    struct node *next;
};

/* Function to insert a node at the beginning */
void push(struct node ** head_ref, int new_data)
{
    struct node* new_node =
           (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}

/* Utility function to print a singly linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *reverse(struct node *head,int k)
{
    struct node *temp=head,*temp1=NULL,*prev=NULL,*temp2=NULL;


        int i=1;
        while(temp!=NULL&&i<=k)
        {
            temp1=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp1;
            i++;

        }

     if(temp1!=NULL)
            head->next=reverse(temp1,k);


return prev;
}

int main()
{
     struct node *p = NULL;
     push(&p, 1);
     push(&p, 2);
     push(&p, 3);
      push(&p, 4);
     push(&p, 5);
     push(&p, 6);
     push(&p, 7);
     push(&p, 8);
     printf("Second Linked List:\n");
     printList(p);

     p=reverse(p,3);

     printf("reversed:\n");
     printList(p);


     getchar();
     return 0;
}
