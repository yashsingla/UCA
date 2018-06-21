#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *newNode(int key)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};
/*
int fun(struct node *root,int sum)
{
      if(!root)
        return 0;

   sum=sum*10+root->key;

   if(!root->left&&!root->right){
       cout<<sum<<endl;
        return sum;
   }

   return fun(root->left,sum)+fun(root->right,sum);
}
*/
int fun1(struct node *root,int *sum,int *result)
{
      if(!root)
        return 0;

   (*result)=(*result)*10+root->key;

   if(!root->left&&!root->right){

    (*sum)=(*sum)+(*result);

   }

       int x= fun1(root->left,sum,result);
         x=fun1(root->right,sum,result);
    (*result)=(*result)/10;
return x;
}
//both fun and fun1 are correct

void wrapper(struct node *root)
{
    int sum=0,result=0;
    //sum=fun(root,sum);
    fun1(root,&sum,&result);
    cout<<"sum:"<<sum;
}


int main()
{
struct node *root=newNode(1);
root->left=newNode(2);
root->left->left=newNode(4);
root->left->right=newNode(6);
root->right=newNode(3);
//root->right->left=newNode(4);
root->right->right=newNode(7);
//root->right->left->left=newNode(1);
//root->right->left->right=newNode(2);
//root->right->right->right=newNode(6);

wrapper(root);
}
