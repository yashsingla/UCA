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

void next_word(struct node *root,char str[],int level,char str1[],int *p)
{
    if(!root)
        return;
   next_word(root->left,str,level,str1,p);
   str[level]=root->key;

    if(root->isleaf==1)
    {
        str[level+1]='\0';
        if(*p==1)
        {
            cout<<"Next word to "<<str1<<" is "<<str<<endl;
            *p=0;
            return;
        }

        if(strcmp(str,str1)==0)
            *p=1;

        //cout<<str<<endl;
    }
    next_word(root->eq,str,level+1,str1,p);
    next_word(root->right,str,level,str1,p);
}


void wrapper(struct node *temp)
{
insert_node(&temp,"apple");
insert_node(&temp,"apes");
insert_node(&temp,"banana");
insert_node(&temp,"cat");
insert_node(&temp,"dog");

int level=0;
char str[20];
int p=0;
cout<<"content of the dictionary:"<<endl;
display(temp,str,level);
cout<<endl;
next_word(temp,str,level,"apple",&p);
}


int main()
{
struct node *temp=NULL;
wrapper(temp);
}
