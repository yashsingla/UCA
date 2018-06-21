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

void preOrder(struct node *root)
{
    stack <struct node*>s;
    struct node *temp=root;

    while(1)
    {
        if(temp)
        {    cout<<temp->key<<" ";
             s.push(temp);
            temp=temp->left;
        }
        else if(!s.empty()&&!temp)
        {
            temp=s.top();
            s.pop();
            temp=temp->right;


        }
        else
        {
            if(s.empty())
                break;
        }

    }//while ends
}//function ends;
void print(struct node *head)
{
       if(!head)
           return;

       print(head->left);
     cout<<head->key<<endl;
     print(head->right);

}

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

preOrder(root);
}

