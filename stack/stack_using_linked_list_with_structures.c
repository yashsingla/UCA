#include<stdio.h>
#include<stdlib.h>

struct interval
{
    int start;
    int end;
};

struct sNode
{
    struct interval key;
    struct sNode *next;
};

struct stack
{
    struct sNode *top;
};

struct stack *createStack()
{
    struct stack *s=(struct stack*)malloc(sizeof(s));
    s->top=NULL;
    return s;
};

struct sNode *createNode(struct interval key)
{
    struct sNode *temp=(struct sNode*)malloc(sizeof(temp));
    temp->key=key;
    temp->next=NULL;
    return temp;
};

void push(struct stack *s,struct interval key)
{
    if(!s->top)
    {
        s->top=createNode(key);
        return;
    }

    struct sNode *temp=createNode(key);
    temp->next=s->top;
    s->top=temp;
}

struct sNode *pop(struct stack *s)
{
    if(!s->top)
    {
      return NULL;
    }

    struct sNode *temp=s->top;
    s->top=s->top->next;
    return temp;
}

void print(struct stack *s)
{   struct sNode *temp1=s->top;

    while(temp1)
    {
        struct interval temp=temp1->key;
        printf("[%d,%d]\n",temp.start,temp.end);
        temp1=temp1->next;
    }

}


int main()
{
struct stack *s=createStack();
struct interval a[]={{1,9},{2,4},{4,5},{0,3}};

int n=sizeof(a)/sizeof(a[0]);

int i;
  for(i=0;i<n;i++)
    push(s,a[i]);

  print(s);
}
