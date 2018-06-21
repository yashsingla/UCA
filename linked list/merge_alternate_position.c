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


void merge(struct node *a,struct node **b)
{
    while(a&&(*b))
    {
        struct node *aNext=a->next;
        struct node *bNext=(*b)->next;
        a->next=(*b);
        (*b)->next=aNext;
        (*b)=bNext;
        a=aNext;
    }

}

int main()
{
     struct node *p = NULL, *q = NULL;
     push(&p, 3);
     push(&p, 2);
     push(&p, 1);
     printf("First Linked List:\n");
     printList(p);

     push(&q, 8);
     push(&q, 7);
     push(&q, 6);
     push(&q, 5);
     push(&q, 4);
     printf("Second Linked List:\n");
     printList(q);

     merge(p,&q);

     printf("Modified First Linked List:\n");
     printList(p);

     printf("Modified Second Linked List:\n");
     printList(q);

     getchar();
     return 0;
}
