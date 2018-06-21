//time complexity of complete code:O(N);

//time complexity for max_heapify:O(2*logN) which is O(logN),twice because each swap takes 2 comparison at each level,so total levels are logN
//i..e.. 2*logN

//space complexity for max_heapify is same as space complexity for convert_max : O(logN),which is due to recursive calls

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

int largest;
int l=2*i+1;
int r=2*i+2;

if(l<n&&a[l]>a[i])
    largest=l;
else
    largest=i;

if(r<n&&a[r]>a[largest])
    largest=r;

if(largest!=i)
{
    swap(&a[i],&a[largest]);
    max_heapify(a,largest,n);
}


}


void convert_max(int a[],int n)
{
    int i;
    for(i=(n-2)/2;i>=0;i--)
        max_heapify(a,i,n);
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
    int a[]={1,14,10,8,7,9,16,2,4,6,-100};
    int n=sizeof(a)/sizeof(a[0]);

    printf("Before Heapifying:\n");
    print(a,n);

    convert_max(a,n);

    printf("After Heapifying:\n");
    print(a,n);

}
