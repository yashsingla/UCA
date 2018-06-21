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
    temp->next=NULL;
    temp->key=key;
    return temp;
};

void push(struct stack *s,struct interval key)
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

 int compare(const void *p,const void *q)
        {
            int l=((struct interval*)p)->start;
            int r=((struct interval*)q)->start;
            return l-r;
        }


void merge_intervals(struct interval a[],int n)
{
qsort(a,n,sizeof(a[0]),compare);

struct stack *s=createStack();

push(s,a[0]);
int i;
for(i=1;i<n;i++)
{
   struct interval top=s->top->key;

   if(top.end<a[i].start)
        push(s,a[i]);
   else
    if(top.end<a[i].end)
   {
        top.end=a[i].end;
        pop(s);
        push(s,top);
   }

}//for ends

while(s->top!=NULL)
{
    struct interval temp=s->top->key;
    printf("[%d,%d]\t",temp.start,temp.end);
    pop(s);
}

}//function ends

int main()
{
struct interval a[]={{2,4},{1,3},{5,7},{6,8}};
int n=sizeof(a)/sizeof(a[0]);

 merge_intervals(a,n);
}

