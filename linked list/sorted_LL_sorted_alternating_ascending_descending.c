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
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = NULL;
    if(*head_ref)
    (*head_ref)->next=new_node;

    *head_ref=new_node;
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

struct node *reverse(struct node *root)
{
    struct node *temp=root;
    struct node *prev=NULL;

    while(temp)
    {  struct node *temp1=temp->next;
        temp->next=prev;
        prev=temp;
        temp=temp1;
    }
    return prev;
};

struct node *merge(struct node *odd,struct node *even)
{  struct node *list=NULL;

    if(!odd)
    return even;
else
    if(!even)
    return odd;

    if(odd->data<=even->data)
    {
        list=odd;
        list->next=merge(list->next,even);
    }
    else
    {
        list=even;
        list->next=merge(odd,list->next);

    }
return list;

};

struct node *sort(struct node *head)
{
   struct node *odd=head;
   struct node *even=head->next;

   while(odd&&even)
   {
       odd->next=even->next;
       odd=odd->next;

       if(!odd)
        break;

       even->next=odd->next;
       even=even->next;

      if(!even)
        break;

   }

   if(odd)
    odd->next=NULL;

   if(even)
    even->next=NULL;

   even=reverse(even);

  return merge(odd,even);

}

int main()
{
     struct node *p = NULL, *q = NULL;
     push(&p, 10);
     struct node *root=p;
     push(&p, 40);
     push(&p, 53);
     push(&p, 30);
     push(&p, 67);
     push(&p, 12);
     push(&p, 89);


     printf("First Linked List:\n");
     printList(root);

    q=sort(root);

     printf("Modified First Linked List:\n");
     printList(q);

      getchar();
     return 0;
}
