#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define alpha_size 26

struct trieNode
{
int frequency;
struct trieNode *children[alpha_size];
int isLeaf;
int indexMinHeap;
};

struct minHeapNode
{
    struct trie *root;
    int frequency;
    char *word;
};

struct minHeap
{
    unsigned capacity;
    int count;
    struct  minHeapNode *array;
};

struct trieNode *getNode()
{
    struct trieNode *root=(struct trieNode*)malloc(sizeof(struct trieNode));
    root->frequency=0;
    root->isLeaf=0;
    root->indexMinHeap=-1;

    int i;

    for(i=0;i<alpha_size;i++)
    root->children[i]=NULL;

    return root;
}

struct minHeap *createHeap(int n)
{
    struct minHeap *root=(struct minHeap*)malloc(sizeof(struct minHeap));
    root->capacity=n;
    root->count=0;
    root->array=(struct minHeapNode*)malloc(sizeof(struct minHeapNode)*n);
    return root;
};

void swapp(struct minHeapNode *a,struct minHeapNode *b)
{
    struct minHeapNode temp=(*a);
    (*a)=(*b);
    (*b)=temp;
}

void min_heapify(struct minHeap *Hnode,int i)
{
int smallest;
int left= 2*i+1;
int right= 2*i+2;

if(left<Hnode->count&&Hnode->array[left].frequency<Hnode.array[i].frequency)
    smallest=left;
else
    smallest=i;

if(right<Hnode->count && Hnode->array[right].frequency<Hnode.array[smallest].frequency)
    smallest=right;

   if(smallest!=i)
   {
       Hnode->array[smallest].root->index=i;
       Hnode->array[i].root->index=smallest;

       swapp(&Hnode->array[smallest],&Hnode->array[i]);
       min_heapify(Hnode,smallest);
   }


}

void buildHeap(struct minHeap *Hnode)
{
    int i;
    int n=Hnode->count-1;
    for(i=(n-1)/2;i>=0;i--)
        min_heapify(Hnode,i);
}

void insertInMinHeap(struct minHeap *Hnode,struct trieNode **root,char str2[],int s)
{   //cas-1: when word if already present

    if((*root)->indexMinHeap!=-1)
    {
      (Hnode->array[(*root)->indexMinHeap].frequency)++;
      minHeapify(Hnode,(*root)->indexMinHeap);
    }
    else //case 2: when heap is not full and word is not present
         if(Hnode->count<Hnode->capacity)
    {
      int count=Hnode->count;
      Hnode->array[count].frequency=(*root)->frequency;
      //Hnode->array[count].root=(*root);
      Hnode->array[count].word=(char*)malloc(sizeof(char)*s);
      strcpy(Hnode->array[count].word,str2);

      Hnode->array[count].root=(*root);

    (*root)->indexMinHeap=Hnode->count;
    ++(Hnode->count);
    buildMinHeap(Hnode);
    }
    else if((*root)->frequency>Hnode->array[0].frequency )
    {
        Hnode->array[0].root->indexMinHeap=-1;
        Hnode->array[0].root=(*root);
        Hnode->array[0].root->indexMinHeap=0;
        Hnode->array[0].frequency=(*root)->frequency;

        free(Hnode->array[0].word);
        Hnode->array[0].word=(char*)malloc(sizeof(char)*s);
        strcpy(Hnode->array[0].word,str2);
        minHeapify(Hnode,0);
    }
}

//insert new word in trie and heap
void insertUtil(char str1[],char str2[],struct minHeap *Hnode,struct trieNode **root,int s)
{
  int index;

    int i;

    for(i=0;str1[i]!='\0';i++)
    {
        index=str1[i]-'a';
       if((*root)->children[index]==NULL)
        (*root)->children[index]=getNode();

       (*root)=(*root)->children[index];
    }

     if((*root)->isLeaf)
        (*root)->frequency++;
     else
     {
         (*root)->isLeaf=1;
        (*root)->frequency=1;
     }
        insertInMinHeap(Hnode,root,str2,s);


}

void insertTrieAndHeap(char a[],struct minHeap *Hnode,struct trieNode **root,int s)
{
insertUtil(a,a,Hnode,root,s);
}

void printMostFreq(char a[][10],int n,int k)
{
    struct minHeap *heapNode=createHeap(k);
    struct trieNode *root=NULL;

    int i=0;
    while(i<n)
    {
        int s=sizeof(a[i])/sizeof(a[i][0]);
        insertTrieAndHeap(a[i],heapNode,&root,s);
        i++;
    }

}

int main()
{
    int k=3;
    char a[][10]={"the","is","the","them","them","them","this","the","them","is","are","when","where","there","their","these"};
    int n=sizeof(a)/sizeof(a[0]);
    printf("%d",n);

   printMostFreq(a,n,k);
}
