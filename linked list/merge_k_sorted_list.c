//time complexity:O(nklogk)

#include<stdio.h>
#include<stdlib.h>

struct node {

int data;
struct node *next;

};

struct node *newNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(temp));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct node *sorted_merge(struct node *a,struct node *b)
{  struct node *result=NULL;
    if(a==NULL)
        return b;
    else
        if(b==NULL)
        return a;

    if(a->data<=b->data)
    {
        result=a;
        result->next=sorted_merge(a->next,b);
    }
    else
    {
        result=b;
        result->next=sorted_merge(a,b->next);

    }
    return result;
};

struct node *mergeKLists(struct node *a[],int n)
{
    int last=n;

    while(last!=0)
    {
        int i=0,j=last;
        while(i<j)
        {
            a[i]=sorted_merge(a[i],a[j]);
            i++,j--;

            if(i>=j)
              last=j;
        }//inner while
    }//outer while

return a[0];

};
void print(struct node *head)
{
    struct node *temp=head;

    while(temp)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main()
{
int n=4,k=3;
struct node *arr[k];

arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    // Merge all lists
   struct node* head = mergeKLists(arr, k - 1);

    print(head);

}
/*
In mergeKlists function...
  let k-1=4..will work till last!=0
1) first cycle
    i=0,last=4

    i=0,j=last=4;

   a[0]=a[0]+a[4];
   a[1]=a[1]+a[3];
   i=2,j=2;
    now a[2] is left as i==j because of which last=2;

 2)cycle 2
    i=0,j=last=2;
    a[0]={a[0]+a[4]}+a[2];
      i=1,j=1;
      now last=j=1;

3) cycle 3
   i=0,j=last=1
   a[0]=a[0]+a[1];
       = {a[0]+a[4]+a[2] }+{a[1]+a[3]};
     i=1,j=0;
     last=j=0; outer loop exits

a[0] is returned
ultimately everything is merged in a[0]
*/
