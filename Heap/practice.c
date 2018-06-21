#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=(*a);
    (*a)=(*b);
    (*b)=temp;
}

void min_heapify(int i,int a[],int n)
{
    int l=2*i+1;
    int r=2*i+2;
   int smaller;

    if(l<n&&a[l]<a[i])
    smaller=l;
    else
        smaller=i;

    if(r<n&&a[r]<a[smaller])
        smaller=r;

    if(i!=smaller)
    {
        swap(&a[i],&a[smaller]);
        min_heapify(smaller,a,n);
    }
}

void del_min(int a[],int n)
{

}

int extract_min(int a[],int *n)
{
    int k=a[0];
    a[0]=a[(*n)-1];
    min_heapify(0,a,(*n));
    (*n)=(*n)-1;
    return k;
}

void bottomToUp(int a[],int n,int i)
{
    int parent=(i-1)/2;
    if(a[i]<a[parent])
    {
        swap(&a[i],&a[parent]);
        bottomToUp(a,n,parent);
    }
}

void insert(int key,int a[],int *n)
{  int k=(*n);
    a[k]=key;
    (*n)=k+1;

   bottomToUp(a,*n,k);
}

int min_cost(int a[],int n)
{int i,k,sum=0;
    for(i=(n-1)/2;i>=0;i--)
        min_heapify(i,a,n);
    k=n;
    for(i=1;i<n;i++)
    {
        int x=extract_min(a,&k);
         int y=extract_min(a,&k);
         insert(x+y,a,&k);
         sum+=x+y;
    }
    return sum;
}

int main()
{
    int a[]={4,3,2,6};
    int n=sizeof(a)/sizeof(a[0]);

    int x=min_cost(a,n);
printf("sum1:%d",x);
}
