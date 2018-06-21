#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next;
};

struct node *newNode(int n)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=n;
    temp->next=NULL;
    return temp;
};

struct node *reverse(struct node *root)
{
    struct node *temp=root;
    struct node *prev=NULL;

    while(temp)
    {  struct node *temp1=temp->next;
        temp->next=prev;
        prev=temp;
        temp=temp1;
    }
    return prev;
};


struct node *rearrange(struct node *root)
{
    struct node *slow=root;
    struct node *fast=root->next;

    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    struct node *second=slow->next;
    slow->next=NULL;
    struct node *first=root;
    second=reverse(second);

   struct node *k1=NULL,*k2=NULL;


     while(first!=NULL&&second!=NULL)
{
       k1=first->next;
       k2=second->next;

    first->next=second;
       second->next=k1;

       first=k1;
       second=k2;
}

return root;

}


void print(struct node *root)
{
    while(root)
    {
        printf("%d\n",root->key);
        root=root->next;
    }
}

int main()
{
    struct node *res=NULL;
struct node *a = newNode(5);
    a->next = newNode(7);
    a->next->next = newNode(9);
   a->next->next->next = newNode(8);
   a->next->next->next->next = newNode(-1);
    a->next->next->next->next->next = newNode(-2);

    printf("List A before merge: \n");
    print(a);


    /* merge 2 increasing order LLs in descresing order */
    res = rearrange(a);

    printf("\nMerged Linked List is: \n");
    print(res);
}
