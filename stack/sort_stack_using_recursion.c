/*
In the sorted insert function what we are doing is, first we compare with the topmost element of the stack which is easily
available by pop, now if the new element to be inserted is greater then obviously we just need to push it as its the new largest
 element, if its lesser than we know that the old top of the stack is still the largest element, and the new element's position
  is somewhere deeper inside the stack. So we are popping the topmost element. Now the problem reduces to inserting the new
  element into the stack with its original largest element popped.
Now when we call the same function again(recursion) in the stack , the new frame is above the old frame, and in this new frame
everything is recomputed as usual and so the stack for this new frame is the new stack(without its largest element) and the temp
 here is a new variable and it doesn't contain the originally popped element as this is a different frame in the stack.
Now finally when we return back to the previous frame(1st call) we already have this new element inserted somewhere deep inside
 the stack, so we push back the original largest element(stored in temp in the current frame) back to the top of the stack.
*/


/*
It's a classic example of PassByValue and PassByReference.
1) we do not want any change in our stack in case of printStack(top) //PassByValue
2) To modify our stack in case of push and sort we have to pass arguments by their reference//PassByReference

*/


#include<stdio.h>
#include<stdlib.h>

struct stack{

int data;
struct stack *next;
};

void initTop(struct stack **s)
{
    *s=NULL;
}

int isEmpty(struct stack *s)
{
    if(s==NULL)
        return 1;
    return 0;
}

void push(int x,struct stack **s)
{
    struct stack *p=(struct stack*)malloc(sizeof(struct stack));

    if(p==NULL)
    printf("memory cannot be located");

  p->data=x;
  p->next=*s;
  *s=p;

}

int  pop(struct stack **s)
{  struct stack *temp;
    int x=(*s)->data;
    temp=*s;
    (*s)=(*s)->next;

    free(temp);
    return x;
}

int top(struct stack *s)
{
    return (s->data);
}

void inserted_sort(struct stack **s,int x)
{
    if(isEmpty(*s)||x>top(*s))
    {
        push(x,s);
        return ;
    }

    int temp=pop(s);
    inserted_sort(s,x);

inserted_sort(s,temp);
   //push(temp,s);
}


void sort(struct stack **s)
{
if(!(isEmpty(*s)))
{
    int x=pop(s);

    sort(s);

    inserted_sort(s,x);
}
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
push(30,&top);
push(-5,&top);
push(18,&top);
push(14,&top);
push(-3,&top);

print(top);

sort(&top);
printf("\n\n");
print(top);
}
