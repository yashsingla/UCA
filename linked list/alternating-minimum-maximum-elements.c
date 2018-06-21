//this code will show segmentation fault for negative values as x=0 and x=1000 is inappropriate for
//negative value to compare  with

//for all negative numbers in input i have changed x= -1000 in max funtion,it then works perfectly fine

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
    int key;
    struct node *next;
};


void push(struct node **head,int key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=key;
    temp->next=*head;
    *head=temp;
}

struct node *max(struct node *root)
{
    int x=INT_MIN;

    struct node *temp=root;
    struct node *temp1=NULL;

    while(temp)
    {
       if(temp->key>x)
       {
           x=temp->key;
           temp1=temp;
       }//if ends
       temp=temp->next;
    }//while ends
    return temp1;
};

struct node *min(struct node *root)
{
    int x=INT_MAX;

    struct node *temp=root;
    struct node *temp1=NULL;

    while(temp)
    {
       if(temp->key<x)
       {
           x=temp->key;
           temp1=temp;
       }//if ends
       temp=temp->next;
    }//while ends
    return temp1;
};

void swap1(int *x,int *y)
{
int temp=*x;
   (*x)=(*y);
   (*y)=temp;
}


void swap(int **x,int **y)
{
    int temp=(**x);
    (**x)=(**y);
    (**y)=temp;
}

void arrange(struct node *root)
{

    struct node *temp=root;
    struct node *temp1=NULL;

    while(temp)
    {
        temp1=min(temp);
        swap1(temp,temp1);
        if(temp->next)
        temp=temp->next;
        else
            break;


         temp1=max(temp);
        swap1(temp,temp1);
        if(temp->next)
        temp=temp->next;
        else
            break;



    }//while ends


}//funtion arrange ends


void print(struct node *root)
{
    struct node *temp=root;
    while(temp)
    {
        printf("%d\n",temp->key);
        temp=temp->next;
    }
}

int main()
{
struct node *root=NULL;
struct node *result=NULL;
push(&root,-1);
push(&root,-3);
push(&root,-8);
push(&root,-2);
push(&root,-7);
push(&root,-5);
push(&root,-6);
push(&root,-4);


arrange(root);

printf("print list:");
print(root);


}
