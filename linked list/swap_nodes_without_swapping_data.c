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

void print(struct node *root)
{
    while(root!=NULL)
    {
        printf("%d\n",root->key);
        root=root->next;
    }
}

void swap(struct node **head,int x,int y)
{
    struct node *Xprev=NULL,*Xnext=NULL;
    struct node *Yprev=NULL,*Ynext=NULL;
    struct node *prev=NULL,*Ynode=NULL,*Xnode=NULL,*temp=(*head);

                while(temp)
                {
                    if(temp->key==x)
                    {
                        Xnode=temp;
                        Xprev=prev;
                        Xnext=temp->next;
                    }

                    if(temp->key==y)
                    {
                        Ynode=temp;
                        Yprev=prev;
                        Ynext=temp->next;
                    }
                    prev=temp;
                    temp=temp->next;
                }

                if(Xprev)
                    Xprev->next=Ynode;
                else
                    (*head)=Ynode;
                Ynode->next=Xnext;

                if(Yprev)
                    Yprev->next=Xnode;
                else
                    (*head)=Xnode;
                Xnode->next=Ynext;
        }

int main()
{
    struct node *root=NULL;
    newNode(&root,10);
    newNode(&root,15);
    newNode(&root,12);
    newNode(&root,13);
    newNode(&root,20);
    newNode(&root,14);

   printf("Before Swaping:\n");
     print(root);

    swap(&root,10,14);

     printf("\n\nAfter Swaping:\n");
     print(root);
}
