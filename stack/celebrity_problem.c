//time complexity :O(n)
//space complexity:O(n)
/*
ALGORITHM:
>>If A knows B, then A can’t be celebrity. Discard A, and B may be celebrity.
>>If A doesn’t know B, then B can’t be celebrity. Discard B, and A may be celebrity.
>>Repeat above two steps till we left with only one person.
>>Ensure the remained person is celebrity. (Why do we need this step?)

We can use stack to verity celebrity.

>>Push all the celebrities into a stack.
>>Pop off top two persons from the stack, discard one person based on return status of HaveAcquaintance(A, B).
>>Push the remained person onto stack.
>>Repeat step 2 and 3 until only one person remains in the stack.
>>Check the remained person in stack doesn’t have acquaintance with anyone else.
*/
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

int mat[4][4]={ {0,0,0,1},
                {0,0,0,1},
                {0,0,0,1},
                {0,0,0,1},
             };

int know(int a,int b)
{
    return mat[a][b];
}
int findCelebrity(int n)
{

struct stack *s=createStack();
int i;

for(i=0;i<n;i++)
    push(s,i);

while(s->top->next!=NULL)
{
    int a=s->top->key;
    pop(s);
    int b=s->top->key;
    pop(s);
int celeb;
    if(know(a,b))
         celeb=b;
    else
        celeb=a;

   push(s,celeb);

}//while ends
int celeb=s->top->key;
pop(s);

  for(i=0;i<n;i++)
    if(know(celeb,i)==1||!know(i,celeb))
       return -1;
  return celeb;

}

int main()
{

int n=4;
int x=findCelebrity(n);

if(x==-1)
    printf("there is no celebrity");
else
    printf("celebrity is:%d",x);

}
