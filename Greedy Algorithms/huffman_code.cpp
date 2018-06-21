#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

struct node
{
    int key;
    char ch;
    struct node *left;
    struct node *right;
    int b;
};

struct node *createNode(int k1,char c1,char p)
{
    struct node *temp=new node;
    temp->key=k1;
    temp->ch=c1;
    temp->left=NULL;
    temp->right=NULL;

    if(p=='l')
        temp->b=0;
    else if(p=='r')
        temp->b=1;
        else
       temp->b=-1;

};

void swap1(char *x,char *y)
{
    char temp= *x;
    (*x) = (*y);
    (*y) = temp;
}

void swap2(int *x,int *y)
{
    int temp= *x;
    (*x) = (*y);
    (*y) = temp;
}

void min_heapify(map<char,int>&m,char arr[],int freq[],int n,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int smallest;

    if(left<n&& m[arr[i]]>m[arr[left]] )
        smallest=left;
        else
            smallest=i;

    if(right<n&& m[arr[smallest]]>m[arr[right]] )
        smallest=right;

    if(i!=smallest)
    {
        swap1(&arr[i],&arr[smallest]);
        swap2(&freq[i],&freq[smallest]);
        min_heapify(m,arr,freq,n,smallest);
    }
}

char extractMin(char arr[],int freq[],int *n,map<char,int>&m)
{
      char temp=arr[0];
      arr[0]=arr[(*n)-1];
      min_heapify(m,arr,freq,(*n)-1,0);
      (*n)=(*n)-1;
      return temp;
}

void bottom_to_up(int parent,int k,char arr[],int freq[],map<char,int>&m)
{
    if( (m[arr[parent]]) > (m[arr[k]]) )
    {
        swap1(&arr[parent],&arr[k]);
        swap2(&freq[parent],&freq[k]);
        bottom_to_up( (parent-1)/2,parent,arr,freq,m);
    }
}

void insert_min_heap(char ch,int val,char arr[],int freq[],map<char,int>&m,int *n)
{
    int k=(*n);
    arr[k]=ch;
    freq[k]=val;
    int parent=(k-1)/2;

  bottom_to_up(parent,k,arr,freq,m);

   (*n)=k+1;
}

struct node *createMinHeap(char arr[],int freq[],int n)
{
    struct node *temp=NULL;

map<char,int> m;
map<int,struct node*> n1;

int i;

 for(i=0;i<n;i++)
 m[arr[i]] = freq[i];

 for(i=(n-1)/2;i>=0;i--)
 min_heapify(m,arr,freq,n,i);

int k=n;
 for(i=0;i<n-1;i++)
 {
     char a=extractMin(arr,freq,&k,m);
     char b=extractMin(arr,freq,&k,m);

     int val=m[a]+m[b];
     char ch=char(i+'0');
     m[ch]=val;

     insert_min_heap(ch,val,arr,freq,m,&k);

     cout<<"val:"<<val<<endl;

       temp=createNode(val,ch,'m');
          n1[val]=temp;

       if(n1[m[a]]==NULL){
        temp->left=createNode(m[a],a,'l');
       }
       else{
        temp->left=n1[m[a]];
       temp->left->b=0;
       }

       if(n1[m[b]]==NULL){
        temp->right=createNode(m[b],b,'r');
      }
       else{
        temp->right=n1[m[b]];
       temp->right->b=1;
       }
     m.erase(a);
     m.erase(b);
}
return temp;
}

void printArr(int p[],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<p[i];

    cout<<endl;
}

void traverse(struct node *root,int p[],int top)
{
    if(root->left)
    {
        p[top]=0;
        traverse(root->left,p,top+1);
    }

    if(root->right)
    {
        p[top]=1;
        traverse(root->right,p,top+1);
    }

   if(!root->left&&!root->right)
   {
       cout<<root->ch<<":";
       printArr(p,top);
   }
}


void wrapper(char arr[],int freq[],int n)
{
 struct node *root=createMinHeap(arr,freq,n);

   //cout<<root->right->right->ch;
   int p[15];
 traverse(root,p,0);
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
   // int freq[] = {45, 9, 16, 13, 12, 5};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int s = sizeof(arr)/sizeof(arr[0]);

    wrapper(arr,freq,s);
}
