// Given a matrix of size n*n containing random integers, give an algo which checks whether ith row matches with jth column
// solution is using trie data structure
#include<iostream>
#include<string>
#include<limits.h>

using namespace std;

struct node
{
    //int key;
    int isLeaf;
    struct node *children[26];
};

struct node *create_node()
{
    struct node *temp= new node;
    //temp->key=key;
    temp->isLeaf=0;

    int i;
    for(i=0;i<26;i++)
    temp->children[i]=NULL;

 return temp;
};

void insert_trie(struct node *root, int a[4][4], int col, int n)
{
 int j;
for(j=0;j<n;j++)
{
    int index=a[j][col];
    if(!root->children[index])
    root->children[index]=create_node();
    root=root->children[index];
}
root->isLeaf=1;
}

int search_trie(struct node *root, int a[4][4], int row, int n)
{
 int j;
for(j=0;j<n;j++)
{
    int index=a[row][j];
    if(!root->children[index])
        return 0;

    root=root->children[index];
}
return root!=NULL && root->isLeaf;
}


void wrapper(int a[4][4],int n)
{
struct node *root=create_node();

int i;
for(i=0;i<n;i++)
insert_trie(root,a,i,n);

for(i=0;i<n;i++)
if(search_trie(root,a,i,n))
   cout<<i<<" th row matches";
}

int main()
{
int a[4][4]={{1,2,3,4},
             {5,6,7,8},
             {3,7,11,15},
             {13,14,15,16}
            };

wrapper(a,4);
}
