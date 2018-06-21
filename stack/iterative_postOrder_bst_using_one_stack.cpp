/*
ALGORITHM:
1. Push root to first stack.
2. Loop while first stack is not empty
   2.1 Pop a node from first stack and push it to second stack
   2.2 Push left and right children of the popped node to first stack
3. Print contents of second stack
*/


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

void print(struct node *head)
{
       if(!head)
           return;

       print(head->left);
     cout<<head->key<<endl;
     print(head->right);

}


void postOrder(struct node *root)
{
    stack <struct node*>s;
    struct node *temp=root;
    struct node *temp1;

 while(1)
    {
        if(temp)
        {
            s.push(temp);
            temp=temp->left;
        }
        else
            if(!s.empty())
        {
            temp=s.top();
            if(!temp->right||temp->right->key==temp1->key)
            {
                cout<<temp->key<<" ";
                temp1=temp;
                s.pop();
                temp=NULL;
            }
            else
            {
               temp=temp->right;

            }//inner else 1 ends

        }//main else ends
        else if(s.empty())
            break;
    }//while ends

}//function ends;}


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

postOrder(root);
}


