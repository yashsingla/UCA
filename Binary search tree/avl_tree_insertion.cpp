#include<iostream>
#include<cmath>
#include<limits.h>

using namespace std;

struct node
{
    int key;
    struct node *left,*right;
    int height;
};

struct node *new_node(int key)
{
    struct node *temp= new node;
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=1;

    return temp;
};

int maxi(int a,int b)
{
    return a>b?a:b;
}

int height(struct node *root)
{
    if(!root)
    return 0;

    return root->height;
}

struct node *rotate_left(struct node *root)
{
    struct node *x=root->right;
    x->left=root;
    root->right=x->left;

    root->height=maxi(height(root->left),height(root->right))+1;
    x->height=maxi(height(x->left),height(x->right))+1;

    return x;
};

struct node *rotate_right(struct node *root)
{
    struct node *x=root->left;
    root->left=x->right;
    x->right=root;

    root->height=maxi(height(root->left),height(root->right))+1;
    x->height=maxi(height(x->left),height(x->right))+1;

    return x;
};

struct node *insert_node(struct node *root ,int key)
{
   if(!root)
    return new_node(key);

   if(key<root->key){
    root->left=insert_node(root->left,key);
   }
   else
   if(key>root->key){
    root->right=insert_node(root->right,key);
   }

    root->height= 1 + maxi( height(root->left),height(root->right) );

    int balance= height(root->left)-height(root->right);

     if(balance>1&&key<root->left->key) // LL case
      return  rotate_right(root);

     if(balance<-1&&key>root->right->key) // RR case
       return rotate_left(root);

      if(balance>1&&key>root->left->key){ // LR case
         root->left=rotate_left(root->left);
      return rotate_right(root);
      }

      if(balance<-1&&key<root->right->key){ // RL case
       root->right=rotate_right(root->right);
       return rotate_left(root);
      }


    return root;
};

void delete_node(struct node *root,int key)
{
    if(!root)
        return;

    if(key<root->key)
    root->left=delete_node(root->left,key);
    else
        if(key>root->key)
    root->right=delete_node(root->right,key);

  else{ //if we found the node to be deleted

    if(!root->left||!root->right) // there is one child or no child for the node to be deleted
    {
        struct node *temp=root->left?rot->left:root->right;

        if(!temp)
        {
            temp=root;
            root=null;
        }
        else
            root->key=temp->key;

        free(temp);
    }
    else // node to be deleted has both right and left child
    {
        struct node * temp=mini(root->right);
        root->key=temp->key;
        root->right=delete_node(root->right,temp->key);
    }
  }

   if(root==null) // single node in tree
    return root;
   //---------------------- this is simply the balancing part , same as done in insertion
   root->height= 1 + maxi( height(root->left),height(root->right) );

    int balance= height(root->left)-height(root->right);

     if(balance>1&&key<root->left->key) // LL case
      return  rotate_right(root);

     if(balance<-1&&key>root->right->key) // RR case
       return rotate_left(root);

      if(balance>1&&key>root->left->key){ // LR case
         root->left=rotate_left(root->left);
      return rotate_right(root);
      }

      if(balance<-1&&key<root->right->key){ // RL case
       root->right=rotate_right(root->right);
       return rotate_left(root);
      }


    return root;

}

void inorder(struct node *root)
{
    if(!root)
        return;

    inorder(root->left);
    cout<<"key: "<<root->key<<endl;
    cout<<"height: "<<root->height<<endl;
    cout<<endl;

    inorder(root->right);
}


void wrapper()
{

struct node *root=NULL;

root=insert_node(root,21);
root=insert_node(root,26);
root=insert_node(root,30);
root=insert_node(root,9);
root=insert_node(root,4);

inorder(root);
}

int main()
{
    wrapper();
}
