//space complexity:O(L),L is length of string
#include<iostream>
#include<string>

using namespace std;

struct node
{
    char key;
    int end_of;
    struct node *left;
    struct node *eq;
    struct node *right;
};

struct node *newNode(char ch)
{
    struct node *temp=new node;
    temp->key=ch;
    temp->end_of=0;
    temp->left=NULL;
    temp->eq=NULL;
    temp->right=NULL;;
    return temp;
};

//time complexity:O(L),L is length of string
void insert_ternary_tree(struct node **temp,char *s)
{
    if(!(*temp))
    {
        (*temp)=newNode(*s);
    }

   if(*s<(*temp)->key)
    insert_ternary_tree(&(*temp)->left,s);
   else

   if(*s>(*temp)->key)
    insert_ternary_tree(&(*temp)->right,s);

   else
     if((*s)==(*temp)->key)
   {
       if(*(s+1))
          insert_ternary_tree(&(*temp)->eq,s+1);
   else
       (*temp)->end_of=1;
   }
};

//time complexity:O(L),L is length of string
int search_ternary(struct node *temp,char *s)
{
   if(!temp)
     return 0;
   if((*s)<temp->key)
      return search_ternary(temp->left,s);
   else
   if((*s)>temp->key)
    return search_ternary(temp->right,s);
   else{
       if(temp->end_of&&*(s+1)=='\0')
        return 1;

        return search_ternary(temp->eq,++s);
      }
}

void display(struct node *temp,char *buffer,int depth)
{
    if(!temp)
        return;

    display(temp->left,buffer,depth);

    buffer[depth]=temp->key;

    if(temp->end_of==1)
    {
        buffer[depth+1]='\0';
        cout<<buffer<<", ";
    }

    display(temp->eq,buffer,depth+1);

    display(temp->right,buffer,depth);
}


void wrapper(char s[],int n)
{
    struct node *temp=NULL;
    insert_ternary_tree(&temp,"baby");
    insert_ternary_tree(&temp,"babyp");

    insert_ternary_tree(&temp,"bye");
    insert_ternary_tree(&temp,"bakib");
    insert_ternary_tree(&temp,"kapil");
    insert_ternary_tree(&temp,"indira");
    insert_ternary_tree(&temp,"babi");
    insert_ternary_tree(&temp,"yash");
    insert_ternary_tree(&temp,"ash");


   char buffer[15];
   display(temp,buffer,0);

   cout<<endl<<endl;

    char k[]="bye";
   if(search_ternary(temp,k))
       cout<<"string is present";
     else
        cout<<"string is not present";
}

int main()
{
char s[]="boat";
int n=sizeof(s)/sizeof(s[0]);
wrapper(s,n);
}
