#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=(*a);
    (*a)=(*b);
    (*b)=temp;
}


void max_heapify(int a[],int i,int n)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest;

    if(l<n&&a[l]>a[i])
        largest=l;

    if(r<n&&a[r]>a[largest])
        largest=r;

    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        max_heapify(a,largest,n);
    }

}

void heap_sort(int a[],int n)
{ int i;
    for(i=n/2-1;i>=0;i--)
      max_heapify(a,i,n);

     for(i=n-1;i>=0;i--)
     {
         swap(&a[0],&a[i]);
         max_heapify(a,0,i);
     }


}


void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d\n",a[i]);
}

int main()
{
    int a[]={12,11,13,5,6,7};
    int n=sizeof(a)/sizeof(a[0]);

    heap_sort(a,n);

   printf("sorted array:\n");
   print(a,n);
}
