/*for 1st solution
Time Complexity of hashing based solution can be considered as O(n) under the assumption that we have good hashing function
that allows insertion and retrieval operations in O(1) time. In the above C++ implementation, map of STL is used.
map in STL is typically implemented using a Self-Balancing Binary Search Tree where all operations take O(Logn) time.
Therefore time complexity of above implementation is O(nLogn).
*/
#include<iostream>
#include<vector>
#include<map>
#include<stdio.h>
#include<queue>

using namespace std;

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *newNode(int key)
{
    struct node *temp=new node;
    temp->left=NULL;
    temp->right=NULL;
    temp->key=key;
return temp;
};
/* nlon(n) solution
void print(struct node *root,map<int,vector<int> >&m,int hd)
{
    if(!root)
      return;
   m[hd].push_back(root->key);

    print(root->left,m,hd-1);
     print(root->right,m,hd+1);
}

void printVerticalOrder(struct node *root)
{
    map<int,vector<int> >m;
    int hd=0;
    print(root,m,hd);

   map<int,vector<int> >::iterator it;
   int i;
   for(it=m.begin();it!=m.end();it++)
   {
       for(i=0;i<it->second.size();i++)
        cout<<it->second[i]<<" ";
       cout<<endl;
   }
}
*/

//Time Complexity : O(n)
//Auxiliary Space : O(n)
void printVerticalOrder(struct node *root)
{
       if(!root)
         return;

    map<int,vector<int> >m;

    queue<pair<int,struct node*> >q;

    int hd=0;

    q.push(make_pair(hd,root));

    while(!q.empty())
    {
   pair<int ,struct node*>temp=q.front();
   q.pop();

   struct node *root1=temp.second;
   hd=temp.first;

   m[hd].push_back(root1->key);

   if(root1->left)
    q.push(make_pair(hd-1,root1->left));

   if(root1->right)
    q.push(make_pair(hd+1,root1->right));

    }//while ends

  map<int,vector<int> >::iterator it;
  int i;
  for(it=m.begin();it!=m.end();it++)
  {
      for(i=0;i<it->second.size();i++)
        cout<<it->second[i]<<" ";
      cout<<endl;
  }
}//function ends

int main()
{
struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    printVerticalOrder(root);
}
