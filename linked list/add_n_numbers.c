#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next;
};

struct node **newNode(struct node **root,int n)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=n;
    temp->next=*root;
    *root=temp;
    return root;
};


struct node *sum(struct node *first,struct node *second,struct node *third)
{
    struct node *prev=NULL,*res=NULL;
    int carry=0;

    while(first||second||third)
    {//while starts

        int sum=carry+(first?first->key:0)+(second?second->key:0)+(third?third->key:0);

        if(sum>=10)
        carry=sum/10;
        else
            carry=0;

       sum=sum%10;

     newNode(&res,sum);

       if(first)
    first=first->next;

    if(second)
    second=second->next;

    if(third)
    third=third->next;

    }//while ends

  if(carry>0)
    newNode(&res,carry);

return res;
};


void print(struct node *root)
{
    while(root)
    {
        printf("%d",root->key);
        root=root->next;
    }
}



int main()
{

struct node *first=NULL;
struct node *second=NULL;
struct node *third=NULL;
struct node *result=NULL;

newNode(&first,1);
newNode(&first,0);
newNode(&first,0);
//newNode(&first,5);
//newNode(&first,7);

//print(first);

//newNode(&second,2);
newNode(&second,2);
newNode(&second,0);
newNode(&second,0);

newNode(&third,3);
newNode(&third,0);
newNode(&third,0);

result=sum(first,second,third);


//printf("\n\n");
print(result);

}
