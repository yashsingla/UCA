#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *down;
};

struct Node *newNode(int new_data)
{
   struct Node* new_node = (struct Node*)malloc(sizeof(new_node));
    new_node->data = new_data;
    new_node->next = new_node->down = NULL;
    return new_node;
}

/*void flatten_depth(struct Node *root)
{
    if(root==NULL)
        return;

    printf("%d\n",root->data);
    if(root->down)
      flatten_depth(root->down);

      flatten_depth(root->next);
}*/

struct node *flatten_depth(struct Node *root)
{
    if(!root)
        return;

    static struct Node *last;
    last=root;
    struct Node *next=root->next;

    struct Node *result=NULL;

    result=root;

    if(root->down)
    result->next=flatten_depth(root->down);

    if(next)
    last->next=flatten_depth(next);

    return root;
};

void print(struct Node *root)
{
    while(root)
    {
        printf("%d\t",root->data);
        root=root->next;
    }
}

int main()
{
    // Creating above example list
   struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->down = newNode(7);
    head->next->down->down = newNode(9);
    head->next->down->down->down = newNode(14);
    head->next->down->down->down->down
                                     = newNode(15);
    head->next->down->down->down->down->next
                                     = newNode(23);
    head->next->down->down->down->down->next->down
                                      = newNode(24);
    head->next->down->next = newNode(8);
    head->next->down->next->down = newNode(16);
    head->next->down->next->down->down = newNode(17);
    head->next->down->next->down->down->next
                                      = newNode(18);
    head->next->down->next->down->down->next->next
                                      = newNode(19);
    head->next->down->next->down->down->next->next->next
                                      = newNode(20);
    head->next->down->next->down->down->next->next->next->down
                                      = newNode(21);
    head->next->down->next->next = newNode(10);
    head->next->down->next->next->down = newNode(11);

    head->next->down->next->next->next = newNode(12);

head=flatten_depth(head);
print(head);
  return 0;
}
