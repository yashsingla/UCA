/*
Method 1 (Simple Solution) A simple way is to one by once search every node of first tree in second tree.
 Time complexity of this solution is O(m * h) where m is number of nodes in first tree and h is height of second tree.

Method 2 (Linear Time) We can find common elements in O(n) time.
1) Do inorder traversal of first tree and store the traversal in an auxiliary array ar1[]. See sortedInorder() here.
2) Do inorder traversal of second tree and store the traversal in an auxiliary array ar2[]
3) Find intersection of ar1[] and ar2[]. See this for details.


ALGORITHM:
1) this approcah is similar to iterative inorder traversal
2) here we are maintaining 2 stacks for 2 trees
time complexity:O(n);
space complexity:O(h1+h2);
*/

#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

struct node
{
    int key;
    struct node *left,*right;
};



struct node *newNode(int item)
{    struct node *temp;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->key=item;
     temp->left=NULL;
     temp->right=NULL;
     return temp;
};


struct node *insert(struct node *root,int n)
{
    if(root==NULL)
    return newNode(n);

    if(n<root->key)
        root->left=insert(root->left,n);
    else
        if(n>root->key)
      root->right=insert(root->right,n);

    return root;
};

void print_common(struct node *root1,struct node *root2)
{
    stack<struct node*>s1,s2;
      while(1)
      {
         if(root1)
         {
             s1.push(root1);
             root1=root1->left;
         }// 1st if ends
         else
         if(root2)
         {
             s2.push(root2);
             root2=root2->left;
         }//2nd if ends
         else  if(!s1.empty()&&!s2.empty())
         {
             root1=s1.top();
             root2=s2.top();

            if(root1->key==root2->key)
            {
              cout<<root1->key<<endl;
              s1.pop();
              s2.pop();

              root1=root1->right;
              root2=root2->right;

            } //if inside main else
            else
                if(root1->key<root2->key)
                {
                  s1.pop();
                  root1=root1->right;

                  root2=NULL;

                 }//first else inside main else

           else

                if(root1->key>root2->key)
                {
                  s2.pop();
                  root2=root2->right;

                  root1=NULL;

                 }//second else inside main else

         }//main outer else ends
       else
        break;

      }//while ends

}//function ends

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
       cout<<root->key<<endl;
        inorder(root->right);
    }

}


int main()
{
struct node *root1 = NULL;
    root1 = insert(root1, 5);
    root1 = insert(root1, 1);
    root1 = insert(root1, 10);
    root1 = insert(root1,  0);
    root1 = insert(root1,  4);
    root1 = insert(root1,  7);
    root1 = insert(root1,  9);

    // Create second tree as shown in example
  struct   node *root2 = NULL;
    root2 = insert(root2, 10);
    root2 = insert(root2, 7);
    root2 = insert(root2, 20);
    root2 = insert(root2, 4);
    root2 = insert(root2, 9);

    cout << "Tree 1 : ";
    inorder(root1);
    cout << endl;

    cout << "Tree 2 : ";
    inorder(root2);

    cout<<endl<<endl<<"common nodes:";
    print_common(root1,root2);

}

