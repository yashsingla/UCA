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

void sort(struct node **root)
{
    struct node *curr=(*root)->next;
    struct node *prev=(*root);

    while(curr)
    {
        if(curr->key<prev->key)
        {
               prev->next=curr->next;

            curr->next=(*root);
            (*root)=curr;

            curr=prev;
           }
           else
           prev=curr;

               curr=curr->next;
    }
}
/*
//number that are negative are put in front
void sort(struct node **root)
{
    struct node *curr=(*root)->next;
    struct node *prev=(*root);

    while(curr)
    {
        struct node *temp=curr->next;

        if(curr->key<0)
        {
        prev->next=curr->next;
        curr->next=(*root);
        (*root)=curr;
        }
        else
            prev=curr;

               curr=temp;
    }
}
*/

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
    struct node *root=NULL;
    root=newNode(1);
    root->next=newNode(-2);
    root->next->next=newNode(-3);
    root->next->next->next=newNode(4);
    root->next->next->next->next=newNode(-5);
    print(root);

   sort(&root);
   printf("\n\nafter sorting:\n");
print(root);
}
