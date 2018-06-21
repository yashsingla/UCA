//time complexity:O(m*n);

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


void mergeList(struct node *a,struct node *b)
{
   struct node *x=a;
   struct node *y=NULL;


   while(x)
   {   y=b;
       if((x->data)>(y->data))
         swap(x,y);

        while(y&&y->next)
        {
            if((y->data)>(y->next->data))
            {
                swap(y,y->next);
            }
            y=y->next;
        }//inner while  ends
     x=x->next;
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
    push(&a, 8);
    push(&a, 7);
    push(&a, 4);
    push(&a, 2);

    struct node *b = NULL;
    push(&b, 12);
    push(&b, 3);
    push(&b, 1);

    printf("Before Merge:");
    print(a);
    printf("\n\n");
    print(b);

    mergeList(a,b);

    printf("After Merge:");
    print(a);
    printf("\n\n");
    print(b);
}
