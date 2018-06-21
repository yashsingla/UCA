#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next;
};

struct node *newNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->next=NULL;
    temp->key=key;
    return temp;
};

struct node *reverse_K_nodes(struct node *root,int k)
{
        if(!root)
            return;

    struct node *temp=root,*temp1=NULL,*prev=NULL;
    int i=1;
    while(i<=k&&temp)
    {
        temp1=temp->next;
        temp->next=prev;
        prev=temp;
        temp=temp1;
        i++;
    }

   root->next=reverse_K_nodes(temp,k);
    return prev;
};

void print(struct node *root)
{
    while(root)
    {
        printf("%d ",root->key);
        root=root->next;
    }
    printf("\n");
}

int main()
{
    int k=2;
    struct node *root=newNode(1);
    root->next=newNode(2);
    root->next->next=newNode(3);
    root->next->next->next=newNode(4);
    root->next->next->next->next=newNode(5);
    root->next->next->next->next->next=newNode(6);

     printf("Original List:");
     print(root);

     root=reverse_K_nodes(root,k);
     printf("Reversed List:");
     print(root);
}
