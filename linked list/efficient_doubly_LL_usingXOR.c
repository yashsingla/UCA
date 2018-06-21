#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next;
};

struct node *createNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->next=NULL;
    temp->key=key;
    return temp;
};

struct node *XOR(struct node *a,struct node *b)
{
return (struct node*)((unsigned int)(a)^(unsigned int)(b));
};

void insert_begin(int key,struct node **head)
{
    if((*head)==NULL)
    {
        (*head)=createNode(key);
        //(*head)->next=XOR(*head,NULL);
        return;
    }

    struct node *temp=createNode(key);
    (*head)->next=XOR(temp,(*head)->next);;
    temp->next=XOR(NULL,*head);
    *head=temp;
}

void delete_begin(struct node **head)
{
    struct node *temp=(*head);
    temp->next->next=XOR(temp,temp->next->next);
    *head=temp->next;
    free(temp);
}

void print(struct node *head)
{
  // following code for printing

   struct node *temp=head;
    struct node *temp1=head->next;
   struct node *temp2=NULL;

    while(temp1)
    {
        printf("%d ",temp->key);
        temp2=temp;
        temp=temp1;
        temp1=XOR(temp2,temp1->next);
    }
    printf("%d\n\n",temp->key);
// following code for printing right to left
     temp1=temp2;
     temp2=NULL;

    while(temp1)
    {
        printf("%d ",temp->key);
        temp2=temp;
        temp=temp1;
        temp1=XOR(temp2,temp1->next);
    }
    printf("%d ",temp->key);

}

int main()
{
    struct node *head=NULL;
    insert_begin(1,&head);
    insert_begin(2,&head);
    insert_begin(3,&head);
    //printf("%d",head->key);
    //delete_begin(&head);
    //printf("%d",head->key);
      print(head);
}
