#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct sNode
{
    int key;
    struct sNode *next;
};

struct stack
{
    struct sNode *top;
    int min;
};

struct stack *createStack()
{
    struct stack *s=(struct stack*)malloc(sizeof(s));
    s->top=NULL;
    s->min=INT_MAX;
    return s;
};

struct sNode *createNode(int key)
{
    struct sNode *temp=(struct sNode*)malloc(sizeof(temp));
    temp->next=NULL;
    temp->key=key;
    return temp;
};

int getTop(struct stack *s)
{
    if(!s->top){
        printf("stack is empty");
      return INT_MIN;
    }

   if(s->top->key>s->min)
    return s->top->key;
   else
    return s->min;

}


void push(struct stack *s,int key)
{  int x;
    if(s->top==NULL)
    {
       s->top=createNode(key);
       s->min=key;
        return;
    }

  if(key>s->top->key)
        x=key;
    else
        {
            x=(2*key)-(s->min);
            s->min=key;
        }

   struct sNode *temp=createNode(x);
    temp->next=s->top;
    s->top=temp;
}

int pop(struct stack *s)
{
     if(s->top==NULL)
     {
         printf("stack is empty");
         return INT_MIN;
     }

   int k=getTop(s);
   s->top=s->top->next;
int x;
     if(k<s->min){
        x=s->min;
        s->min=2*(s->min)-(k);
    }
    else
        x=k;


    return x;
};

int getMin(struct stack *s)
{
    if(!s->top){
        printf("stack is empty");
      return INT_MIN;
    }

    return s->min;
}


int main()
{
struct stack *s=createStack();

push(s,3);
push(s,5);

 int x=getMin(s);
if(x!=INT_MIN)
printf("minimum element:%d\n",x);

push(s,2);
push(s,1);

 x=getMin(s);
if(x!=INT_MIN)
printf("minimum element:%d\n",x);

x=pop(s);
if(x!=INT_MIN)
printf("top element removed:%d\n",x);

x=getMin(s);
if(x!=INT_MIN)
printf("minimum element:%d\n",x);

x=pop(s);
if(x!=INT_MIN)
printf("top element removed:%d\n",x);

x=getTop(s);
if(x!=INT_MIN)
printf("top element:%d\n",x);

}
