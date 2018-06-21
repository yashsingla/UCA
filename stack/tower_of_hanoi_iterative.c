// application of tower of hanoi:
//1. The Tower of Hanoi is also used as a Backup rotation scheme when performing computer data Backups where multiple tapes/media are involved.
//2. Tower of hanoi is also used in medical field by neuologist  to evaluate frontal lobe deficit
// 3. used to teach  recursion
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Snode
{
    int key;
    struct Snode *next;
};

struct stack
{
    struct Snode *top;
};

struct stack *createStack()
{
    struct stack *s=(struct stack*)malloc(sizeof(s));
    s->top=NULL;
    return s;
};

struct Snode *createNode(int key)
{
    struct Snode *node=(struct Snode*)malloc(sizeof(node));
    node->key=key;
    node->next=NULL;
    return node;
};

void push(struct stack *s,int key)
{
       if(!s->top)
       {
           s->top=createNode(key);
           return;
       }

    struct Snode *temp=createNode(key);
    temp->next=s->top;
    s->top=temp;

}

int pop(struct stack *s)
{
       if(s->top==NULL)
        return -1;

    int temp=s->top->key;
    s->top=s->top->next;
    return temp;
}

void move(int k,char a,char b,int i){
printf("i=%d\tmove disc %d from %c to %c\n",i,k,a,b);
}

void tower_recursive(struct stack *src,struct stack *dest,char s,char d,int i)
{
        int p1=pop(src);
        int p2=pop(dest);

        if(p1==-1)
        {
            push(src,p2);
            move(p2,d,s,i);
        }
        else
        if(p2==-1)
        {
            push(dest,p1);
            move(p1,s,d,i);
        }
        else
            if(p1>p2)
        {
            push(src,p1);
            push(src,p2);
            move(p2,d,s,i);
        }
        else
        {
            push(dest,p2);
            push(dest,p1);
            move(p1,s,d,i);
        }
}

void print(struct stack *s)
{
    if(s->top==NULL)
    printf("stack is empty");

  struct Snode *temp=s->top;

  while(temp!=NULL)
  {
      printf("%d\n",temp->key);
      temp=temp->next;
  }

}


void tower(int n,struct stack *src,struct stack *dest,struct stack *aux)
{

     char s='S',d='D',a='A';

    if(n%2==0)
    {
        char temp=d;
        d=a;
        a=temp;
    }
// if we will not interchange dest and aux for even values then result will show up in aux stack instead of dest stack.
//try the code without interchange and u will see the result in aux stack;
   int x=pow(2,n)-1;

int i;
for(i=n;i>=1;i--)
    push(src,i);

   for(i=1;i<=x;i++)
   {
       if(i%3==1)
        tower_recursive(src,dest,s,d,i);
       else
       if(i%3==2)
        tower_recursive(src,aux,s,a,i);
       else
        if(i%3==0)
        tower_recursive(aux,dest,a,d,i);
   }
}

int main()
{
    int n=4;
    struct stack *src,*dest,*aux;

    src=createStack();
    dest=createStack();
    aux=createStack();

    tower(n,src,dest,aux);
}
