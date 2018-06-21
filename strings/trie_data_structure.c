//time complexity :1)insert :O(N),2) search:O(N),where N is length of string to be inserted
//space complexity: let k be the avg length of strings.. O(alpha_size*k*n),where n is the number of strings

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define alpha_size 26
#define bool int
#define true 1
#define false 0

struct node
{
    struct node *children[alpha_size];
    bool isLeaf;
};

struct node *createNode()
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    int i;

    for(i=0;i<alpha_size;i++)
        p->children[i]=NULL;

    p->isLeaf=false;
    return p;
};

void insert(struct node *root1, char *str)
{
    //int index;
    int n=strlen(str);
   struct node *root=root1;
int i;
   for(i=0;i<n;i++)
   {
      int index= str[i]-'a';
    if(root->children[index]==NULL)
     root->children[index]=createNode();

   root=root->children[index];

   }
   printf("1\n");
   root->isLeaf=true;
}

bool search(struct node *root,char str[])
{
    int n=strlen(str);
    int i;
  struct node *root1=root;

    for(i=0;i<n;i++)
    {
        int index=str[i]-'a';
    if(root1->children[index]==NULL)
        return false;

      root1=  root1->children[index];
    }
    return root1!=NULL&&root1->isLeaf;
}

bool isLeafNode(struct node *root)
{
    return root->isLeaf!=0;
}

bool isFreeNode(struct node *root)
{
    int i;

    for(i=0;i<alpha_size;i++)
        if(root->children[i])
        return 0;
return 1;
}

bool del_string(struct node *root,char str[],int level,int n)
{
    if(root)
    {
        if(level==n)
        {
            if(root->isLeaf)
                root->isLeaf=0;

            if(isFreeNode(root))
                return true;

            return false;

        }
        else
        {  int index=str[level]-'a';
            if(del_string(root->children[index],str,level+1,n))
            {
                free(root->children[level]);

                return !isLeafNode(root)&&isFreeNode(root);
            }
        }
    }//if ends
return false;
}

void del(struct node *root,char str[])
{
    int n=strlen(str);

    if(n>0)
    {
        del_string(root,str,0,n);
    }
}

int main()
{
    char in[][8]={"the","a","there","answer","any","by","bye","their"};
    char out[][8]={"the","answer","their","yash"};

    int n=sizeof(in)/sizeof(in[0]);
    int n1=sizeof(out)/sizeof(out[0]);

    struct node *root=createNode();
    int j;

    for(j=0;j<n;j++)
    insert(root,in[j]);

    /*for(j=0;j<n1;j++)
    if(search(root,out[j]))
    printf("%s is present\n",out[j]);
    else
         printf("%s is not present\n",out[j]);
*/
if(search(root,"answer"))
    printf("answer is present\n");
    else
         printf("answer is not present\n");

del(root,"answer");

if(search(root,"answer"))
    printf("answer is present\n");
    else
         printf("answer is not present\n");
}
