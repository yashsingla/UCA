#include<iostream>
#include<queue>
#include<limits.h>


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
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

void  wrapper(struct node *root)
{
    int k=0,result,maxi=INT_MIN,nCount=0;
    queue<struct node*>q;
    q.push(root);

    while(!q.empty())
    {//main while starts
        result=0;
        int cnt=1<<k;
        int m;

    while(q.front()==NULL){
                    cnt=cnt-1;
                  q.pop();
                }

        while(cnt)
        {//inner while starts
                 m=0;
               while(q.front()==NULL){
                   m=m+1;
                    cnt=cnt-1;
                  q.pop();
                }
                 if(cnt<=0)
                    break;
                 else
                 {result=result+m;
                  int i;
                  for(i=1;i<=(2*m);i++)
                    q.push(NULL);
                 }

            struct node *temp=q.front();
            q.pop();

           q.push(temp->left);
           q.push(temp->right);

           result++;

        }//inner while ends
       if(result>maxi)
        maxi=result;

        k++;
    }//main while ends
    cout<<"maximum:"<<maxi;
}//function ends


int main()
{
struct node *root=newNode(1);
root->left=newNode(3);
root->left->left=newNode(2);
root->left->left->right=newNode(4);
root->left->left->right->right=newNode(5);
root->left->left->right->left=newNode(6);
root->right=newNode(7);
root->right->right=newNode(8);
root->right->right->right=newNode(9);
root->right->right->right->left=newNode(10);
root->right->left=newNode(11);
root->right->left->right=newNode(12);
root->right->left->right->left=newNode(13);

wrapper(root);
}
