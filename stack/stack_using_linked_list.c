#include<stdio.h>
#include<stdlib.h>

struct sNode
{
    int key;
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

struct sNode *createNode(int key)
{
    struct sNode *temp=(struct sNode*)malloc(sizeof(temp));
    temp->next=NULL;
    temp->key=key;
    return temp;
};

void push(struct stack *s,int key)
{
    if(s->top==NULL)
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
     if(s->top==NULL)
     {
         return NULL;
     }

    struct sNode *temp=s->top;
    s->top=s->top->next;

    return temp;
};

void print(struct stack *s)
{
    if(s->top==NULL)
    printf("stack is empty");

  struct sNode *temp=s->top;

  while(temp!=NULL)
  {
      printf("%d\n",temp->key);
      temp=temp->next;
  }

}

int main()
{

struct stack *s=createStack();

push(s,1);
push(s,2);
push(s,3);
push(s,4);
print(s);
pop(s);
printf("\n");
print(s);
}
