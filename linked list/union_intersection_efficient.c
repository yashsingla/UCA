#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct node
{
    int key;
    struct node *next;
};

void push(struct node **node,int n)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=n;
    temp->next=*node;
    *node=temp;
}




void split_list(struct node *source,struct node **front,struct node **back)
{
    struct node *slow;
    struct node *fast;

   if(source==NULL||source->next==NULL)
   {
       *front=source;
       *back=NULL;
   }
else{

        slow=source;
    fast=source->next;

    while(fast!=NULL){
        fast=fast->next;
    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }

    }
   *front=source;
   *back=slow->next;
   slow->next=NULL;

}

}

struct node *merge(struct node *headA,struct node *headB)
{
    struct node *result=NULL;

    if(headA==NULL)
       return headB;
    else
    if(headB==NULL)
        return headA;

    if(headA->key<=headB->key)
    {
        result=headA;
       result->next=merge(headA->next,headB);

    }
    else
    {
        result=headB;
       result->next=merge(headB->next,headA);

    }

    return result;
}

void mergesort(struct node **head)
{
    struct node *temp1=*head;
    struct node *front=NULL;
    struct node *back=NULL;

    if(temp1==NULL||temp1->next==NULL)
              //*head=temp1;
              return;

    split_list(temp1,&front,&back);

      mergesort(&front);
      mergesort(&back);


*head=merge(front,back);

}


void print(struct node *root)
{
    while(root)
    {
        printf("%d\n",root->key);
        root=root->next;
    }
}

struct node *union_1(struct node *headA,struct node *headB)
{   struct node *result=NULL;

   while(headA&&headB)
   {
       if(headA->key<headB->key){
            //result=headA;
            push(&result,headA->key);
            headA=headA->next;
       }
       else
        if(headB->key<headA->key){
        push(&result,headB->key);
        headB=headB->next;
        }
       else
        if(headA->key==headB->key){
        push(&result,headA->key);
        headB=headB->next;
       headA=headA->next;
   }
//result=result->next;
}


while(headA)
{  push(&result,headA->key);
    //result=headA;
    headA=headA->next;
    result=result->next;

}

while(headB)
{  push(&result,headB->key);
    //result=headB;
    headB=headB->next;
    result=result->next;

}

//print(result);

return result;
}


struct node *inter_1(struct node *headA,struct node *headB)
{   struct node *result=NULL;

   while(headA&&headB)
   {
       if(headA->key<headB->key){
            headA=headA->next;
       }
       else
        if(headB->key<headA->key){
        headB=headB->next;
        }
       else
        if(headA->key==headB->key){
        push(&result,headA->key);
        headB=headB->next;
       headA=headA->next;
   }
//result=result->next;
}

return result;
}



int main()
{
    struct node *root=NULL;
      struct node *root2=NULL;
      struct node *unin=NULL;
    struct node *inter=NULL;


     push(&root,-9);
     push(&root,20);
     push(&root,-1);
     push(&root,30);
     push(&root,25);

    push(&root2,-1);
     push(&root2,14);
     push(&root2,-9);
     push(&root2,27);
     push(&root2,21);


     mergesort(&root);
     mergesort(&root2);
   unin=union_1(root,root2);
   inter=inter_1(root,root2);

    printf("union\n");
    print(unin);

printf("\n\nIntersection\n");
print(inter);

     getch();//getche or getchar
     return 0;

}

