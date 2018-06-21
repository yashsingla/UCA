#include<stdio.h>
#include<stdlib.h>

struct qNode
{
    struct qNode *prev,*next;
    int page;
};

struct queue
{
    int count;
    int capacity;
    struct qNode *front,*rear;
};

struct hash
{
int hCapacity;
struct qNode **array
};

struct queue *createQueue(int x)
{
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->capacity=x;
    q->count=0;
    q->front=NULL;
    q->rear=NULL;
    return q;
};

struct qNode *createQnode(int x)
{
    struct qNode *node=(struct qNode*)malloc(sizeof(struct qNode));
    node->page=x;
    node->next=NULL;
    node->prev=NULL;
    return node;
};

struct hash *createHash(int x)
{
    struct hash *node=(struct hash*)malloc(sizeof(struct hash));
    node->hCapacity=x;
    node->array=(struct qNode**)malloc(sizeof(struct qNode*));
int i;
    for(i=0;i<x;i++)
    node->array[i]=NULL;

    return node;
};

int isFull(struct queue *q)
{
    return q->capacity==q->count;
}

int isEmpty(struct queue *q)
{
    if(!q->rear)
        return 1;
    return 0;
}

void deQueue(struct queue *q)
{
    if(isEmpty(q))
        return;

    if(q->rear==q->front)
      q->front=NULL;


    struct node *temp=q->rear;
    q->rear=q->rear->prev;

   if(q->rear)
    q->rear->next=NULL;


        free(temp);

   q->count--;
}

void enQueue(struct queue *q,struct hash *h,int page)
{
    struct qNode *temp=createQnode(page);

    if(isEmpty(q))
      {
          q->front=q->rear=temp;
          return;
      }

    if(isFull(q))
     {
         h->array[q->rear->page]=NULL;
          deQueue(q);
     }

     temp->next=q->front;
      temp->next->prev=temp;
      q->front=temp;

      h->array[page]=temp;
      q->count++;
}


void referPage(struct queue *q,struct hash *h,int page)
{
    struct qNode *node=h->array[page];

    if(!node)
        enQueue(q,h,page);
    else
        if(node!=q->front)
    {
      struct qNode *front=node->next;
    struct qNode *back=node->prev;


    back->next=front;
    if(front)
    front->prev=back;

     if(node==q->rear)
     {
         q->rear=node->prev;
         q->rear->next=NULL;
     }


    node->prev=NULL;
    node->next=q->front;
    node->next->prev=node;

   q->front=node;
   }
}


int main()
{
int x=4;

struct queue *q=createQueue(x);
struct hash *h=createHash(x);

    referPage(q,h,1);
    referPage(q,h,2);
    referPage(q,h,3);
    referPage(q,h,1);
    referPage(q,h,4);
    referPage(q,h,5);

    printf("pages in queue:");
    printf("%d,",q->front->page);
    printf("%d,",q->front->next->page);
    printf("%d,",q->front->next->next->page);
    printf("%d,",q->front->next->next->next->page);

}
