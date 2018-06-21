#include<stdio.h>
#include<stdlib.h>

struct node
{
    char key;
    struct node *next;
};

struct stack
{
    struct node *top;
};

struct stack *createStack()
{
    struct stack *s=(struct stack*)malloc(sizeof(s));
    s->top=NULL;
    return s;
};

struct node *createNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=key;
    temp->next=NULL;
    return temp;
};

void push(struct stack *s,int key)
{
    if(!s->top){
    s->top=createNode(key);
    return;
    }

    struct node *temp=createNode(key);
      temp->next=s->top;
      s->top=temp;
}

int pop(struct stack *s)
{
    if(!s->top){
    return -1;
    }

    struct node *temp=s->top;
      s->top=s->top->next;
      int x=temp->key;
      free(temp);
      return x;
}

int iSempty(struct stack *s)
{
    if(s->top!=NULL)
        return 1;
    else
        return 0;
}

int stackTop(struct stack *s)
{
    if(!s->top)
        return -1;
    return s->top->key;
}

int isOperand(char ch)
{
    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
        return 1;
    return 0;
}

int prec(char ch)
{
 switch(ch)
 {
     case '+':
     case '-':
         return 1;

     case '*':
     case '/':
         return 2;

     case '^':
         return 3;

}
return -1;
}

void infixTopostfix(char a[],int n)
{
    struct stack *s=createStack();
    int i,k=-1;

    for(i=0;i<n;i++)
    { //for starts
        if(isOperand(a[i])) //if one
            a[++k]=a[i];
        else
            if(a[i]==')')
        { //if two starts
            while(iSempty(s)&&s->top->key!='(')
            {
                a[++k]=pop(s);
            }pop(s);
        } //if two ends
     else
        if(a[i]=='(')  //if three
           push(s,a[i]);
     else
     { //last else starts
         while(iSempty(s)&&prec(stackTop(s))>=prec(a[i]))
         {
             a[++k]=pop(s);
         }
         push(s,a[i]);
     }// last else ends
    }//for ends
    while(!iSempty(s))
      a[++k]=pop(s);

    a[++k]='\0';

printf("infixTopostfix:%s",a);
}//function ends

int main()
{
    char exp[]="a+b*(c^d-e)^(f+g*h)-i";
    int n=sizeof(exp)/sizeof(exp[0]);

   printf("Original:%s\n",exp);

    infixTopostfix(exp,n);
}
