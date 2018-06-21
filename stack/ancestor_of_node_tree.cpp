//using iterative preorder traversal

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

void ancestor(struct node *root,int x)
{
       if(root->key==x)
       {
           cout<<"NO ancestor present"<<endl;
           return;
       }

    stack <struct node*>s;
    struct node *temp=root;
    struct node *temp1=NULL;
    struct node *temp2=NULL;
    while(1)
    {
        if(temp)
        {    if(temp->key==x)
                 break;
             s.push(temp);
            temp=temp->left;
        }
        else if(!s.empty())
        {
            temp1=s.top();
             if(!temp1->right||temp2->key==temp1->right->key){
                  temp2=temp1;
                  s.pop();
                  temp=NULL;
             }
             else
            temp=temp1->right;
        }
    }//while ends

    while(!s.empty())
      {
         temp=s.top();
         s.pop();
         cout<<temp->key<<" ";
      }
}//function ends;

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

ancestor(root,3);
}
