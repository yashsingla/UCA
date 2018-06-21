#include<stdio.h>
#include<stdlib.h>

struct node
{
    int x,y;
    struct node* next;
};


struct node* newNode(int x,int y)
{
   struct  node *temp = (struct node*)malloc(sizeof(temp));;
    temp->x = x;
    temp->y = y;
    temp->next = NULL;
    return temp;
}

void delete_middle(struct node **temp)
{
      struct node *temp1=(*temp);
      (*temp)=(*temp)->next;
      free(temp1);
}

void fun(struct node *head)
{
    if(!head||!head->next||!head->next->next)
             return;

    struct node *temp=head;
    struct node *temp1=temp;

          while(1){
    if(temp->x==temp->next->x)
    {   temp=temp->next;
            while(temp&&temp->next&&(temp->x==temp->next->x))
            {
                delete_middle(&temp);

            }//inner while ends

           temp1->next=temp;

           if(!temp->next)
           break;

          else
          temp1=temp;
  }//main if ends

    else
    {
          temp=temp->next;
      while(temp&&temp->next&&(temp->y==temp->next->y))
            {
                delete_middle(&temp);

            }//inner while ends

           temp1->next=temp;

           if(!temp->next)
           break;

        else
     temp1=temp;
  }//main else ends
} //main while ends
}//main function ends

void print(struct node *root)
{
    struct node *temp=root;
    while(temp)
    {
        printf("(%d,%d)->",temp->x,temp->y);
        temp=temp->next;
    }
}


int main()
{
   struct node *head = newNode(2,3);
    head->next = newNode(4,3);
    head->next->next = newNode(6,3);
    head->next->next->next = newNode(10,3);
    head->next->next->next->next = newNode(12,3);
    //head->next->next->next->next->next = newNode(20,5);
   // head->next->next->next->next->next->next = newNode(40,5);


    fun(head);
    print(head);
}


