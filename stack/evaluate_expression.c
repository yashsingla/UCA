#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct sNode
{
    char key;
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

struct sNode *createNode(char key)
{
    struct sNode *temp=(struct sNode*)malloc(sizeof(temp));
    temp->next=NULL;
    temp->key=key;
    return temp;
};

void push(struct stack *s,char key)
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

int higherPre(char str,char top)
{
      if((str=='-'||str=='+')&&(top=='*'||top=='/'||top=='-'||top=='+'))
        return 1;
      else
        return 0;

}

char *infixToPostfix(char *str)
{
    int i=0,j=0;
    char temp[strlen(str)];
    struct stack *s=createStack();

    while(str[i]!='\0')
    {
        if(isdigit(str[i]))
          temp[j++]=str[i];
       else
            if(!isdigit(str[i]))
       {//if 2 starts
              if(!s->top)
                push(s,str[i]);
             else
             {
                 while(s->top&&higherPre(str[i],s->top->key))
                 {
                     temp[j++]=s->top->key;
                     pop(s);
                 }push(s,str[i]);

             }//else ends


       }// if 2 ends

      i++;
    }//while ends

    while(s->top)
    {
        temp[j++]=s->top->key;
        pop(s);
    }temp[j]='\0';
   //printf("%s",temp);
return temp;
}//function ends

char *perform(char a2[],char a1[],char op)
{
    int x2=atoi(a2);
    int x1=atoi(a1);
    int result;

    if(op=='+')
    result=x1+x2;
    else
        if(op=='-')
    result=x1-x2;
    else
        if(op=='*')
    result=x1*x2;
else
    if(op=='/')
    result=x1/x2;

char k[3];
itoa(result,k,10);

  return k;
}

int evaluate(char str[])
{
    struct stack *s=createStack();
char *temp=infixToPostfix(str);
int i=0;

while(temp[i]!='\0')
{
    if(isdigit(temp[i]))
        push(s,temp[i]);
    else
        if(!isdigit(temp[i]))
    {
        char a2[]={s->top->key};
        pop(s);

        char a1[]={s->top->key};
        pop(s);

        char r[]=perform(a2,a1,temp[i]);


        push(s,r);
    }
    i++;

}
return s->top->key;
}

int main()
{

char s[]="2*3+5*4-9";
char x=evaluate(s);
int y=atoi(x);
printf("%d",y);
//infixToPostfix(s);
}
