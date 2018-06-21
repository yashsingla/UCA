#include<iostream>
using namespace std;

struct Node
{
    int key;
    Node *next;
};

void push(Node **head, int data)
{
    Node *newnode = new Node;

    newnode->key = data;

    newnode->next = *head;

    *head = newnode;
}

void print(struct Node *root)
{
    while(root)
    {
        cout<<root->key<<" ";
        root=root->next;
    }
}

struct Node *finalMaxSumList(struct Node *list1, struct Node *list2)
{
    while(list1&&list2)
    {
        if(list1->key>list2->key)
        {
            while(list2->key<list1->key)
                list2=list2->next;

            list1=list1->next;
        }
        else if(list1->key==list2->key)
        {
            struct Node *next_1=list1->next;
            struct Node *next_2=list2->next;
            list1->next=next_2;
            list2->next=next_1;
        }
        else if(list1->key<list2->key)
            list1=list1->next;
    }
return list1;
};

int main()
{
    //Linked List 1 : 1->3->30->90->110->120->NULL
    //Linked List 2 : 0->3->12->32->90->100->120->130->NULL
    Node *head1 = NULL, *head2 = NULL;
    push(&head1, 120);
    push(&head1, 110);
    push(&head1, 90);
    push(&head1, 30);
    push(&head1, 3);
    push(&head1, 1);

    push(&head2, 130);
    push(&head2, 120);
    push(&head2, 100);
    push(&head2, 90);
    push(&head2, 32);
    push(&head2, 12);
    push(&head2, 3);
    push(&head2, 0);

   struct Node *root=finalMaxSumList(head1, head2);
    print(root);

    return 0;
}
