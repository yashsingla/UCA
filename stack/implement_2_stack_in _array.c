#include<stdio.h>
#include<stdlib.h>

struct array
{
    int top1;
    int top2;
    int *arr;
    int size;
};

struct array *createArray(int x)
{
    struct array *s=(struct array*)malloc(sizeof(s));
    s->size=x;
    s->top1=-1;
    s->top2=x;
    s->arr=(int*)malloc(s->size*sizeof(int));
    return s;
};


void push1(struct array *s,int x)
{

     if(s->top1<s->top2-1)
     {
         s->top1++;
         s->arr[s->top1]=x;
     }
     else
        printf("stack1 overflow\n");

}

void push2(struct array *s,int x)
{

     if(s->top1<s->top2-1)
     {
         s->top2--;
         s->arr[s->top2]=x;
     }
     else
        printf("stack2 overflow\n");

}

int pop1(struct array *s)
{
    if(s->top1>=0)
    {
        int x=s->arr[s->top1];
        s->top1--;
        return x;
    }
    else
    {
        printf("stack1 underflow\n");
        return;
    }
}

int pop2(struct array *s)
{
    if(s->top2<s->size)
    {
        int x=s->arr[s->top2];
        s->top1++;
        return x;
    }
    else
    {
        printf("stack2 underflow\n");
        return;
    }
}


int main()
{
    int x=5;
    struct array *s=createArray(x);
    push1(s,3);
    push1(s,11);
    push1(s,-8);
    push1(s,-6);
    push2(s,0);

   //printf("element popped from stack1:%d\n",pop1(s));
   push2(s,9);
   printf("element popped from stack2:%d\n",pop2(s));

}
