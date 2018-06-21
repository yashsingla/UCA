//efficient way ..other way to sort the list and swap alternate(O(nlogn))
//time complexity:O(n);

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


void push(struct node **head,int n)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->data=n;
    temp->next=*head;
    *head=temp;
}

void swap(int *x,int *y)
{
int temp=*x;
   (*x)=(*y);
   (*y)=temp;
}


void ZigZag (struct node *a)
{
   struct node *temp=a;
   int flag=1;

   while(temp->next)
   {
       if(flag) /* "<" relation expected */
       {
           /* If we have a situation like A > B > C
               where A, B and C are consecutive Nodes
               in list we get A > B < C by swapping B
               and C */


           if((temp->data)>(temp->next->data))
                  swap(temp,temp->next);

       }//if ends
       else   /* ">" relation expected */
       {
            /* If we have a situation like A < B < C where
               A, B and C  are consecutive Nodes in list we
               get A < C > B by swapping B and C */

         if((temp->data)<(temp->next->data))
                  swap(temp,temp->next);

       }
        temp=temp->next;
   flag=!flag;

   }//while ends


}



void print(struct node *head)
{
    while(head)
    {
        printf("%d\n",head->data);
        head=head->next;
    }
}

int main()
{

    struct node *a = NULL;
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 15);
    push(&a, 11);



    printf("Before Merge:");
    print(a);
    printf("\n\n");


    ZigZag(a);

    printf("After Merge:");
    print(a);



}
