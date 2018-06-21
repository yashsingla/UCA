/*
ALGORITHM:(using single stack)
APPROACH 1(implemented below) space complexity:O(n) due to function call stack
1) pop all the element from stack till u reach null using recursion and store it in variable n;
2 as u reach null ,insert new element at bottom and return(returning will put older elements back to their old positions)

APPROACH 2:(using 2 stacks)
1) first pop all the elements from s1 and push it to s2
2) now push new element to s2(pushed at top)
3)now,push back all elements back from s2 to s1

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
    temp->next=(*head);
    (*head)=temp;
}


int dequeue(struct node **head)
{
    int n=(*head)->key;
    (*head)=(*head)->next;
    return n;
}

void implement(struct node **head,int k)
{
    if(!(*head))
    {
        enqueue(head,k);
        return;
    }
    else
    {
        int n=dequeue(head);
        implement(head,k);
        enqueue(head,n);
    }
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
    enqueue(&q1,2);
    enqueue(&q1,3);
    enqueue(&q1,4);
    enqueue(&q1,5);
    enqueue(&q1,6);
    root=q1;

     printf(" Queue:\n");
     print(root);

    printf("Enter new element to be inserted:");
    scanf("%d",&k);
     printf("\n\n");

   implement(&q1,k);

  printf("updated Queue:\n");
     print(q1);


}
