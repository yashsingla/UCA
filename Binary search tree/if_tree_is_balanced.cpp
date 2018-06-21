//time complexity:O(n^2)
#include<iostream>
#include<cmath>

using namespace std;

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *newNode(int key)
{
    struct node *temp= new node;
    temp->left=NULL;
    temp->right=NULL;
    temp->key=key;
return temp;
};

int maxi(int a,int b)
{
    a>=b?a:b;
}
/*  //O(n^2) solution
int height(struct node *root)
{
    if(!root)
        return 0;
    return 1+maxi(height(root->left),height(root->right));
}

bool fun(struct node *root)
{
    if(!root)
        return true;

    int l=height(root->left);
    int r=height(root->right);

    if(abs(l-r)<=1&&fun(root->left)&&fun(root->right))
        return true;

    return false;
}
*/
//O(n) solution
bool check_balanced(struct node *root,int *height)
{
    int lh=0,rh=0;
    int l=0,r=0;

    if(!root)
    {
        *height=0;
        return 0;
    }
     l=check_balanced(root->left,&lh);
     r=check_balanced(root->left,&rh);

     *height=maxi(l,r)+1;

     if(abs(lh-rh)>=2)
        return false;

        return l&&r;
}

bool fun(struct node *root)
{
    int h=0;
    if(check_balanced(root,&h))
        return true;
    else
        return false;
}

int main()
{
    struct node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    //root->left->right=newNode(5);
    //root->left->right->right=newNode(6);
    //root->left->right->right->right=newNode(7);

    if(fun(root))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
}
