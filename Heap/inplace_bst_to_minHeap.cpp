/*
ALGORITHM:
1) idea is to first convert bst in linked list using reverse inorder traversal
2) now,place left and right pointers to proper place by making parent child relationship using queue
3) now print it in level order .using queue
*/

#include<iostream>
#include<queue>

using namespace std;

struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int n)
{
struct node* temp =new node;
    temp->key = n;
    temp->left = temp->right = NULL;
    return temp;
};


void bstToLL(struct node *root,struct node **head)
{
    if(!root)
      return;

   bstToLL(root->right,head);

    root->right=(*head);

    if(*head!=NULL)
        (*head)->left=NULL;


    (*head)=root;


   bstToLL(root->left,head);

}

void print(struct node *root)
{
    while(root->right)
    {
        cout<<root->key<<endl;
        root=root->right;
    }
}

struct node  *LLtoMinHeap(struct node *head)
{
     queue<struct node*>q;

   struct node *root=head;
   head=head->right;
   root->right=NULL;

    q.push(root);

    while(head)
    {
        struct node *leftchild,*rightchild;
        struct node *parent=q.front();
        q.pop();

       leftchild=head;
       head=head->right;

      leftchild->right=NULL;
      parent->left=leftchild;
      q.push(leftchild);

      if(head)
      {
       rightchild=head;
       head=head->right;

      rightchild->right=NULL;
      parent->right=rightchild;
      q.push(rightchild);

      }

    }
return root;
}

void printLevelOrder(struct node *root)
{ struct node *head=root;

  queue<struct node*>q;

 q.push(head);

 while(!q.empty())
 {
     struct node *data=q.front();
     q.pop();
     cout<<data->key<<endl;

     if(data->left)
    q.push(data->left);

    if(data->right)
    q.push(data->right);
 }


}

struct node *wrapper(struct node *root)
{
    struct node *head=NULL;

    bstToLL(root,&head);
   return LLtoMinHeap(head);
}


int main()
{
    struct node *root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->right->left = newNode(10);
    root->right->right = newNode(14);
    root->left->left = newNode(2);
    root->left->right = newNode(6);

  struct node *head=wrapper(root);

   printLevelOrder(head);
}
