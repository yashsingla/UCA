// C++ program to check if linked list is circular
#include<stdio.h>
#include<stdlib.h>

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};


int isCircular(struct Node *root)
{
    struct Node *temp=root->next;

    while(temp)
    {
        if(temp==root)
            return 1;
        temp=temp->next;
    }

return 0;
}


struct Node *newNode(int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(temp));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


int main()
{

    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    isCircular(head)? printf("Yes\n") :
                      printf("No\n") ;

    // Making linked list circular
    head->next->next->next->next = head;

    isCircular(head)? printf("Yes\n") :
                      printf("No\n") ;

    return 0;
}
