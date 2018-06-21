#include<iostream>
#include<string.h>
#define max_val 26

using namespace std;

struct node
{
    char key;
    int isleaf;
    struct node *left;
    struct node *eq;
    struct node *right;
};

struct node *createNode(char key)
{
    struct node *temp= new node;
    temp->key=key;
    temp->isleaf=0;
    temp->left=NULL;
    temp->eq=NULL;
    temp->right=NULL;
    return temp;
};

void insert_node(struct node **root,char *s)
{
    if(!(*root)){
        (*root)=createNode(*s);
    }
    if((*s)<(*root)->key)
        insert_node(&(*root)->left,s);
    else
    if((*s)>(*root)->key)
        insert_node(&(*root)->right,s);
    else
    if((*s)==(*root)->key){

       if(*(s+1)=='\0')
       {(*root)->isleaf=1;
       return;
       }
        insert_node(&(*root)->eq,s+1);
    }
}

void display(struct node *root,char str[],int level)
{
    if(!root)
        return;
   display(root->left,str,level);
   str[level]=root->key;

    if(root->isleaf==1)
    {
        str[level+1]='\0';
        cout<<str<<endl;
    }
    display(root->eq,str,level+1);
    display(root->right,str,level);
}

int isLeaf(struct node *root)
{
    return root->isleaf==1;
}

int isFreeNode(struct node *root)
{
   if(root->left||root->eq||root->right)
      return 0;
   return 1;
}

int delete_node(struct node *root,char str[],int level,int n)
{
     if(root)
     {
       if(str[level+1]=='\0')
       {
           if(isLeaf(root))
            root->isleaf=0;

            return isFreeNode(root);
       }
       else
       {
               if(str[level]<root->key)
              delete_node(root->left,str,level,n);
        else
               if(str[level]>root->key)
             delete_node(root->right,str,level,n);
        else
            if(str[level]==root->key){ //--1
          if( delete_node(root->eq,str,level+1,n))
          {//-- 2
                   struct node *temp=root->eq;
                  delete(temp);
                  temp=NULL;
                  return !isLeaf(root)&&isFreeNode(root);

          }//-- 2
      }//--1

       }
     }// main if ends
return 0;
}// function ends


void wrapper(struct node *temp)
{
insert_node(&temp,"apple");
insert_node(&temp,"apes");
insert_node(&temp,"banana");
insert_node(&temp,"cat");
insert_node(&temp,"dog");

int level = 0;
char str[20];
int p = 0;

cout<< "1.Content of the dictionary before deletion: " <<endl<<endl;
display(temp ,str ,level);

level = 0;
delete_node(temp ,"banana" ,level ,5);

level = 0;
cout<< endl << "2.Content of the dictionary after deletion: " << endl<< endl;
display(temp ,str ,level);
}

int main()
{
struct node *temp = NULL;
wrapper(temp);
}
