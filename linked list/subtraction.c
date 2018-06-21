#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next;
};

void push(struct node **root,int key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=key;
    temp->next=*root;
    *root=temp;
}

void print(struct node *root)
{
    while(root)
    {
        printf("%d\n",root->key);
        root=root->next;
    }
}

void sum(struct node **result,struct node *root,struct node *root1)
{
    struct node *result1=NULL;
         int a,b;

while(root||root1)
{
    if(root)
        a=root->key;
        else
        a=0;

    if(root1)
    b=root1->key;
    else
        b=0;

  if(a<b)
  {
      struct node *temp=root->next;

      while(temp)
      {
          if(temp->key>0)
          {
              a=10+a;
              temp->key=temp->key-1;
              int sub=a-b;
            push(&result1,sub);
              break;
          }
          else
            if(temp->key==0)
          {
              temp->key=9;
           }
     temp=temp->next;
  }//inner while end

}//if ends
else
{
      int sub=a-b;
            push(&result1,sub);

}
if(root)
root=root->next;

if(root1)
root1=root1->next;

}//outer while

*result=result1;
}

int main()
{
    struct node *result=NULL;
    struct node *root=NULL;
    struct node *root1=NULL;

    push(&root,1);
    push(&root,0);
    push(&root,0);
    //push(&root,1);

    printf("first number:");
    print(root);

    push(&root1,1);
    //push(&root1,9);
    //push(&root1,9);
    //push(&root,0);

    printf("\n\nsecond number:");
    print(root1);

   sum(&result,root,root1);

 printf("\n\nSum:");
    print(result);

}
