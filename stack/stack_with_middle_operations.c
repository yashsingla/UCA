//to find middle of stack in O(1) time...we have used doubly linked list to do that because we need to move
//middle pointer up when we push and middle pointer down when we pop an element
//middle of even number of elements in stack {1,2,3,4} is 2..{1,2,3,4,5,6,7,8} is 4

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct sNode
{
    int key;
    struct sNode *next,*prev;
};

struct stack
{
    struct sNode *top;
    struct sNode *middle;
};

struct stack *createStack()
{
    struct stack *s=(struct stack*)malloc(sizeof(s));
    s->top=NULL;
    s->middle=NULL;
    return s;
};

struct sNode *createNode(int key)
{
    struct sNode *temp=(struct sNode*)malloc(sizeof(temp));
    temp->key=key;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
};

void push(struct stack *s,int key,int *i)
{
    if(!s->top)
    {
        s->top=createNode(key);
        s->middle=s->top;
        s->middle->next=NULL;
        s->middle->prev=NULL;
        (*i)++;
        return;
    }

    struct sNode *temp=createNode(key);
    s->top->next=temp;
    temp->prev=s->top;
    s->top=s->top->next;

    if((*i)%2==0){
        struct sNode *next=s->middle->next->next;
        struct sNode *prev=s->middle;
        s->middle=s->middle->next;
        s->middle->next=next;
        s->middle->prev=prev;
     }
    (*i)++;
}


int pop(struct stack *s,int *i)
{
    if(!s->top)
    {  printf("stack is empty\n");
        return INT_MIN;
    }

    struct sNode *temp=s->top;
    s->top=s->top->prev;
    temp->prev=NULL;
    s->top->next=NULL;

    if((*i)%2!=0){
        struct sNode *next=s->middle;
        struct sNode *prev=s->middle->prev->prev;
        s->middle=s->middle->prev;
        s->middle->next=next;
        s->middle->prev=prev;
    }
    (*i)--;
    int x=temp->key;
    free(temp);
return x;
}


int main(){

struct stack *s=createStack();
int i=0;
push(s,1,&i);
push(s,2,&i);
push(s,3,&i);
//pop(s,&i);
//push(s,4,&i);
//push(s,5,&i);
printf("%d",s->middle->key);
}
