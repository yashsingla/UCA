//time complexity:O(n);
//space complexity:O(n); because of call stack

#include<stdio.h>
#include<stdlib.h>

struct node
{
int key;
struct node *next,*arbit;

};

void fun(struct node *root)
{
    if(!root)
        return;

    static struct node *max;

    if(!root->next)
    {
         max=root;
         return;
    }


    fun(root->next);

    root->arbit=max;

    if(max->key<root->key)
        max=root;
return;
}

void print(struct node *node)
{
    printf("Node\tNext Pointer\tArbit Pointer\n");
    while (node!=NULL)
    {

        printf("%d\t\t",node->key);

        if(node->next)
        printf("%d\t\t",node->next->key);
          else
        printf("NULL\t\t");


        if(node->arbit)
             printf("%d",node->arbit->key);
        else printf("NULL");

        printf("\n");
        node = node->next;
    }
}

struct node *newNode(int data)
{
    struct node *new_node =(struct node*)malloc(sizeof(new_node));
    new_node->key = data;
    new_node->next = NULL;
    return new_node;
}
int main()
{
   struct node *head = newNode(5);
    head->next = newNode(10);
    head->next->next = newNode(2);
    head->next->next->next = newNode(3);

    fun(head);

    printf("Resultant Linked List is: \n");
    print(head);
}
