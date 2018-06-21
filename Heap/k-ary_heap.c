#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=(*a);
    (*a)=(*b);
    (*b)=temp;
}


void k_heap(int a[],int index,int n,int k)
{
    int child[k+1];

   int i;

    while(1){

     for(i=1;i<=k;i++){
  if((k*index+i)<n)
         child[i]=k*index+i;
         else
            child[i]=-1;
            }

   int max_child=-1,max_child_index;

   for(i=1;i<=k;i++)
   {
       if(child[i]!=-1&&a[child[i]]>max_child)
       {
           max_child=a[child[i]];
           max_child_index=child[i];
       }
   }// second for ends

     if(max_child==-1)
        break;

     if(a[index]<a[max_child_index])
     swap(&a[index],&a[max_child_index]);

         index=max_child_index;

}//while ends
}//function ends

void convert_max(int a[],int n,int k)
{
    int i;
    for(i=n/k-1;i>=0;i--)
        k_heap(a,i,n,k);

}

void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);

        printf("\n\n");
}


int main()
{
int a[]={4, 5, 6, 7, 8, 9, 10};
    int n=sizeof(a)/sizeof(a[0]);
    int k=3;

    printf("Before building max-Heap:\n");
    print(a,n);

    convert_max(a,n,k);

    printf("After Heapifying:\n");
    print(a,n);
}
