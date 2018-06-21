#include<stdio.h>
#include<stdlib.h>


void swapp(int *a,int *b)
{
    int temp= *a;
    *a= *b;
    *b=temp;
}

void min_heapify(int arr[],int i,int n)
{
    int left=2*i+1;
    int right=2*i+2;
    int  smallest;

    if(left<n&&arr[left]<arr[i])
        smallest=left;
        else smallest=i;

    if(right<n&&arr[right]<arr[smallest])
        smallest=right;

     if(smallest!=i)
     {
         swapp(&arr[i],&arr[smallest]);
         min_heapify(arr,smallest,n);
     }
}
void build_heap(int arr[],int n)
{
    int i;
    for(i=(n-1)/2;i>=0;i--)
        min_heapify(arr,i,n);
}

int extract_min(int arr[],int *n)
{
    int i=(*n);
    int x=arr[0];
    arr[0]=arr[i-1];
    (*n)=i-1;
   min_heapify(arr,0,i-1);
   return x;
}

void moveUp(int arr[],int n)
{
    int parent=(n-1)/2;

    if(arr[parent]<arr[n-1])
    swapp(&arr[parent],&arr[n-1]);
}

void insert_heap(int arr[],int *n,int k)
{
    int i=(*n);
    arr[i]=k;
    (*n)=i+1;

    moveUp(arr,*n);
}

void cost_util(int arr[],int n)
{
    int sum=0;
   build_heap(arr,n);
    int i;

    while(n>1){
   int a=extract_min(arr,&n);
   int b=extract_min(arr,&n);

    int k=a+b;
    sum=sum+k;

   insert_heap(arr,&n,k);
    }
printf("sum:%d",sum);
}

int main()
{
    int arr[]={4,3,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    cost_util(arr,n);
}
