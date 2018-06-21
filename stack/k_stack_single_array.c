#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct array
{
     int free;
    int *arr;
    int *top;
    int  *next;
    int n,k;
};

struct array *createStack(int n,int k)
{
    struct array *s=(struct array*)malloc(sizeof(s));
    s->free=0;
    s->arr=(int*)malloc(n*sizeof(int));
    s->top=(int*)malloc(k*sizeof(int));
    s->next=(int*)malloc(n*sizeof(int));
    s->n=n;
    s->k=k;

int i;
for(i=0;i<n-1;i++)
  s->next[i]=i+1;
  s->next[n-1]=-1;

for(i=0;i<k;i++)
  s->top[i]=-1;


    return s;
};

void push(int key,int stk,struct array *s)
{
    if(s->free==-1){
        printf("stack overflow");
    return;}

    int i=s->free;
    s->free=s->next[i];
    s->next[i]=s->top[stk];
    s->top[stk]=i;
    s->arr[i]=key;
}

int pop(struct array *s,int stk)
{
    if(s->top[stk]==-1){
    printf("stack underflow\n");
    return INT_MIN;
     }

    int i=s->top[stk];
    s->top[stk]=s->next[i];
    s->next[i]=s->free;
    s->free=i;

    return s->arr[i];
}

int main()
{

int n=5,k=3;
struct array *s=createStack(n,k);

push(15,2,s);
push(45,2,s);
push(9,2,s);
push(11,1,s);
push(19,1,s);
int x=pop(s,1);
if(x!=INT_MIN)
printf("popped element from stack-%d :%d",1,x);
}
