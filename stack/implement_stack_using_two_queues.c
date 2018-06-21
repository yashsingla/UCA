/*
ALGORITHM:
>>Approach 1(implemented below) time complexity:O(n) where n is the number of elements in q1
1) firstly we have elements in q1 ,then we enqueue new element into q2
2) dequeue all elements from q1 and enqueue it into q2 simultaneously
3) return top element by dequeueing q2

>>Approach 2 time complexity:O(n) where n is the number of elements in q1
1) firstly we have elements in q1 ,then we enqueue new element into q1(new element inserted at last in q1)
2) dequeue all elements from q1 except last element and enqueue it into q2 simultaneously
3) return last element of q1 by dequeueing q1

*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next;
};

void enqueue(struct node **head,int n)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=n;
    temp->next=NULL;

    if(*head)
    (*head)->next=temp;
    (*head)=temp;

}

int dequeue(struct node **head)
{
    int n=(*head)->key;
    (*head)=(*head)->next;
    return n;
}

void print(struct node *root)
{
    if(!root)
    printf("queue is empty");

    while(root)
    {
        printf("%d\n",root->key);
        root=root->next;
    }
}

int main()
{
    int k;
    struct node *root=NULL,*root1=NULL;
    struct node *q1=NULL,*q2=NULL;


    enqueue(&q1,1);
    root=q1;

    enqueue(&q1,2);
    enqueue(&q1,3);
    enqueue(&q1,4);
    enqueue(&q1,5);
    enqueue(&q1,6);

     printf("First Queue:\n");
     print(root);

    printf("Enter new element to be inserted:");
    scanf("%d",&k);
     printf("\n\n");

   enqueue(&q2,k);
    root1=q2;

struct node *temp=root,*temp1=root1;

    while(temp)
    {
        int m=dequeue(&temp);
        enqueue(&q2,m);
    }

  printf("stack implemented with 2 queues:\n");
  print(temp1);

  printf("\n\nElement on top:%d",dequeue(&temp1));

}


/*
>>Implementing stack using single queue:
1) enqueue the new element to be inserted..new size (n+1)
2) now,first dequeue ,then enqueue the same till size!=n

*/
