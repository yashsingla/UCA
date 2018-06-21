#include<stdio.h>
#include<stdlib.h>
#define no_of_chars 256

struct node
{
    char key;
    struct node *next;
    struct node *prev;
};

void append(struct node **head,struct node **tail,char key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=key;
    temp->next=temp->prev=NULL;

    if(!(*head))
    {
        (*head)=(*tail)=temp;
        return;
    }

   (*tail)->next=temp;
   temp->prev=(*tail);
   (*tail)=temp;
}

void removee(struct node **head,struct node **tail,struct node *temp)
{
        if((*head)==NULL)
            return;

        if((*head)==temp)
        (*head)=(*head)->next;

        if((*tail)==temp)
        (*tail)=(*tail)->prev;

        if(temp->next!=NULL)
            temp->next->prev=temp->prev;

        if(temp->prev!=NULL)
        temp->prev->next=temp->next;

        temp=NULL;
        free(temp);
}

void firstNonRepeating()
{
    int repeated[no_of_chars];
    char *dll[no_of_chars];
    int i;

    for(i=0;i<no_of_chars;i++)
    {
        repeated[i]=0;
        dll[i]=NULL;
    }

   char a[]="geeksforgeeksandquiz";
char ch,x;
i=0;
struct node *head=NULL,*tail=NULL;
   while(a[i]!='\0')
   { //while starts

x=a[i++];
printf("character read from stream is:%c\n",x);
   if(!repeated[x])
   {
       if(dll[x]==NULL)
       {
           append(&head,&tail,x);
           dll[x]=tail;
       }
       else
       {
           removee(&head,&tail,dll[x]);
           dll[x]=NULL;
           repeated[x]=1;
      }
  }

 printf("first non_repeating character so far is:%c\n",head->key);
 printf("\n\n");

   }//while ends
}//function ends

int main()
{
    firstNonRepeating();
}
