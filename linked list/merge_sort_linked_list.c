#include<stdio.h>
#include<stdlib.h>

struct node
{
int key;
struct node *next;
};

void newNode(struct node **root,int x)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=x;
    temp->next=*root;
    *root=temp;
};


void split_list(struct node *head,struct node **front,struct node **back)
{
    struct node *slow;
    struct node *fast;
    if(head==NULL||head->next==NULL)
    {
        *front=head;
        *back=NULL;
    }
   else{
    slow=head;
    fast=head->next;

    while(fast)
    {
        fast=fast->next;
        while(fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }

    *front=head;
    *back=slow->next;
    slow->next=NULL;
}//else ends
}

struct node *sorted_merge(struct node *headA,struct node *headB)
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
        result->next=sorted_merge(headA->next,headB);

    }
    else
    {
        result=headB;
        result->next=sorted_merge(headB->next,headA);
    }

    return result;
};

void mergesort(struct node **headref)
{
    struct node *a=NULL,*b=NULL,*head=*headref;

    if(!head||!head->next)
           return ;

    split_list(head,&a,&b);

    mergesort(&a);
    mergesort(&b);

   *headref=sorted_merge(a,b);

}



void print(struct node *root)
{
    while(root!=NULL)
    {
        printf("%d\n",root->key);
        root=root->next;
    }
}

int main()
{
    struct node *root=NULL;
    newNode(&root,-9);
    newNode(&root,1);
    newNode(&root,0);
    newNode(&root,8);
    newNode(&root,-2);

   printf("Before sorting:\n");
     print(root);

    mergesort(&root);

     printf("\n\nAfter sorting:\n");
     print(root);
}
