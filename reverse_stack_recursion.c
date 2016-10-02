#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

void initTop(struct stack **s)
{
    (*s)=NULL;
}

int isEmpty(struct stack *s)
{
    if(s==NULL)
        return 1;
    return 0;
}

int top(struct stack *s)
{
    return s->data;
}

void push(struct stack **s,int key )
{
    struct stack *p=(struct stack*)malloc(sizeof(p));

    if(p==NULL)
    {printf("Memory not found");
    return;
    }

  p->data=key;
  p->next=*s;
  *s=p;

}

int pop(struct stack **s)
{
    int x;
    struct stack *temp;
    x=(*s)->data;
    temp=(*s);
    (*s)=(*s)->next;
    free(temp);
    return x;

}

void fun2(struct stack **s,int k)
{

    if(isEmpty(*s))
    {
        push(s,k);
        return;
    }
//else{
     int temp=pop(s);
     fun2(s,k);

      push(s,temp);
//}

}



void fun1(struct stack **s)
{
    if((*s)==NULL)
        return;

   //if(!isEmpty(*s))
    //{
    int x=pop(s);

    fun1(s);

    fun2(s,x);
    //}
}


void print(struct stack *s)
{
    while(s)
    {
        printf("%d\n",s->data);
        s=s->next;
    }
}

int main()
{
struct stack *top;

initTop(&top);
push(&top,-3);
push(&top,5);
push(&top,-1);
push(&top,12);
push(&top,15);

print(top);
fun1(&top);
printf("\n\n");
print(top);
}
