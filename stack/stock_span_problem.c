/*TIME COMPLEXITY:O(N)

ALGORITHM:
1) push value index 0 in stack
2) for each current day strock price ,check if stock price for the  day at stack top is less than current day stock
 price..if so keep on poping till stack becomes empty or stack top becomes greater than current day stock

3) if stack is empty then span for that day is index value of that day plus 1(i+1)
 else span=i-index value at stack top
4) push current day index in stack

*/

#include<stdlib.h>
#include<stdio.h>

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


void fun(int a[],int n,int k[])
{
    struct stack *s=createStack();
    push(s,0);
    k[0]=1;
    int i;
    for(i=1;i<n;i++)
    {
        while(s->top&&a[s->top->key]<=a[i])
            pop(s);
        k[i]= !s->top?i+1:i-s->top->key;
       push(s,i);
    }
}

int main()
{
    int a[]={100,80,60,70,60,75,85};
    int n=sizeof(a)/sizeof(a[0]);
    int s[n];

    fun(a,n,s);

    int i;

    for(i=0;i<n;i++)
    printf("%d\t",s[i]);

getch();
}
