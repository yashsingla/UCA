#include<stdio.h>
#include<stdlib.h>


//time complexity:O(logN) ,by finding the pivot


int findPivot(int a[],int l,int r)
{
    if(l>r)
        return -1;

    if(l==r)
        return l;

    int m=(l+r)/2;

    if(a[m]<a[m-1])
        return m-1;

    if(a[m]>a[m+1])
           return m;

        if(a[l]<=a[m])
        findPivot(a,m+1,r);
        else
        findPivot(a,l,m-1);

}

int binary_search(int a[],int key,int l,int r)
{
    if(l>r)
        return -1;
int    m=(l+r)/2;

    if(a[m]==key)
        return m;
    else
        if(key<a[m])
        return binary_search(a,key,l,m-1);
    else
        return binary_search(a,key,m+1,r);
}

void wrapper(int a[],int n,int key)
{
    int pivot=findPivot(a,0,n-1);
     int index;

    if(pivot==-1) //array is not rotated at all
     index=binary_search(a,key,0,n-1);

  else{

   if(a[pivot]==key)
    index=pivot;
   else
   if(a[0]<=key)
    index=binary_search(a,key,0,pivot-1);

  else
    index=binary_search(a,key,pivot+1,n-1);
}

     if(index==-1)
        printf("element not found");
     else
        printf("element found at index:%d",index);
}



int main()
{
    int a[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n=sizeof(a)/sizeof(a[0]);
    int key=10;
    wrapper(a,n,key);
}
