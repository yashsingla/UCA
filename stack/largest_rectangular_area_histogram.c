//o(n2) solution
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

int hist(int h[],int n)
{
    int i,w,area;
    struct  stack *s=createStack();
    struct  stack *a=createStack();

    for(i=0;i<n;i++)
    {
        w=i+1;

       if(!s->top)
       {
           push(s,h[i]);
           area=h[i]*w;
       }
       else
       {// else 1 starts

           push(s,h[i]);
           int j=1,min=INT_MAX;

           while(j<=w&&s->top)
           {
               int trans=s->top->key;
                 pop(s);
              if(trans<min)
                min=trans;

             int area1=j*min;

             if(area1>area)
             {  printf("old area:%d\n",area);
                printf("new area:%d\n\n",area1);
                area=area1;
             }

           push(a,trans);
               j++;

       }//while ends

           while(a->top)
           {
               push(s,a->top->key);
               pop(a);
           }

       }//else 1 ends

    }//for ends
    return area;
}//function ends


int main()
{
//int a[]={6,2,5,4,5,1,6};
int a[]={1,2,4};
int n=sizeof(a)/sizeof(a[0]);

int x=hist(a,n);
printf("largest area:%d",x);
}
