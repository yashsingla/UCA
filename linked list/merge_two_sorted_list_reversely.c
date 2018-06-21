//space complexity:O(1)&& requires only one traversal...here we compare both lists and insert smaller element in beginning..
//efficient

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next;
};

struct node *newNode(int n)
{
    struct node *temp=(struct node*)malloc(sizeof(temp));
    temp->key=n;
    temp->next=NULL;
    return temp;
};

struct node *SortedMerge(struct node *a,struct node *b)
{
    struct node *x=a;
    struct node *y=b;
    struct node *res=NULL;

    while(x!=NULL&&y!=NULL)
    {

       if(x->key<y->key)
       {
            struct node *temp=x->next;

            x->next=res;
            res=x;

           x=temp;


       }//if 1 ends

   else
   {
       struct node *temp=y->next;

            y->next=res;
            res=y;

           y=temp;

   }//else ends

} //while ends

while(x!=NULL)
{
    struct node *temp=x->next;

            x->next=res;
            res=x;

           x=temp;
}


while(y!=NULL)
{
    struct node *temp=y->next;

            y->next=res;
            res=y;

           y=temp;
}

return res;

}//function ends


void print(struct node *root)
{
    while(root)
    {
        printf("%d\n",root->key);
        root=root->next;
    }
}

int main()
{
    struct node *res=NULL;
struct node *a = newNode(5);
    a->next = newNode(10);
    a->next->next = newNode(15);

  struct  node *b = newNode(2);
    b->next = newNode(3);
    b->next->next = newNode(20);

    printf("List A before merge: \n");
    print(a);

    printf("List B before merge: \n");
    print(b);

    /* merge 2 increasing order LLs in descresing order */
    res = SortedMerge(a, b);

    printf("\nMerged Linked List is: \n");
    print(res);
}
