#include<iostream>
#include<stack>

using namespace std;

struct node
{
    int key;
    struct node *left,*right;
};

struct node *newNode(int key)
{
    struct node *temp=new node;
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

// time complexity:O(N),N are the number of elements in BST
struct node *kth_smallest(struct node *root,int k)
{
    if(!root)
        return NULL ;
    stack<struct node*>s;
    struct node *smallest=NULL,*top;

    while(k!=0)
    {
        if(root)
        {
         s.push(root);
        root=root->left;
        }
        else
        {
            if(!s.empty())
           {
               struct node *top=s.top();
               while(!top->right&&k>0)
               {
                   smallest=top;
                   k--;
                   s.pop();
                   top=s.top();
               }
               if(k>0)
               {
                   root=top->right;
                   smallest=top;
                   s.pop();
                   k--;
               }

            }//inner if ends

        }//else ends

    }//main while ends
    return smallest;
};//function ends

void wrapper(struct node *root,int k)
{
    struct node *root1=kth_smallest(root,k);
    cout<<"kth_smallest:"<<root1->key;

}

int main()
{
    struct node *root=newNode(20);
    root->left=newNode(8);
    root->left->left=newNode(4);
    root->left->right=newNode(12);
    root->left->right->left=newNode(10);
    root->left->right->right=newNode(14);
    root->right=newNode(22);

    int k=5;

    wrapper(root,k);
}
