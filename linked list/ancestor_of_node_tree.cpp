

#include<iostream>
#include<stack>

using namespace std;

struct node
{
    float key;
    struct node *left,*right;
};

struct node *newNode(int n)
{
    struct node *temp=new node;
    temp->left=NULL;
    temp->right=NULL;
    temp->key=n;
    return temp;
};

/* //iterative function
void ancestor(struct node *root,int key)
{
   stack<struct node*>s;
   struct node *head=root,*temp=NULL,*temp1=NULL;

     while(1)
     {

        if(head)
        {
            if(head->key==key)
                break;
            s.push(head);
            head=head->left;
        }
        else
            if(!s.empty())
        {
            temp=s.top();
            if(!temp->right||temp->right->key==temp1->key)
            {
                temp1=temp;
                s.pop();
                temp=NULL;
            }
            else
                head=temp->right;
        }

     }//while ends

     while(!s.empty())
     {
         temp=s.top();
         s.pop();
         cout<<temp->key<<" ";
     }

}//function ends
*/

//recursive function
bool ancestor(struct node *root,int key)
{
        if(!root)
        return false;

      if(root->key==key)
          return true;

      if(ancestor(root->left,key)||ancestor(root->right,key))
      {
            cout<<root->key<<" ";
            return true;
      }

   return false;
}//function ends



int main()
{
struct node *root=newNode(4);
root->left=newNode(2);
root->left->left=newNode(1);
root->left->right=newNode(3);
root->left->right->left=newNode(0);
root->right=newNode(6);
root->right->right=newNode(7);
root->right->right->right=newNode(8);
root->right->left=newNode(5);

bool x=ancestor(root,8);
}
