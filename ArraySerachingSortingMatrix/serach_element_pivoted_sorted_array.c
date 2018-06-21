#include<stdio.h>
#include<stdlib.h>

// most efficient
//time complexity:O(logN) and in single pass

int search_pivoted(int a[],int key,int l,int r)
{
    if(l>r)
        return -1;

    int m=(l+r)/2;

    if(a[m]==key)
        return m;


    if(a[l]<=a[m])
    {
        if(key>=a[l]&&key<=a[m])
            return search_pivoted(a,key,l,m-1);
        else
           return search_pivoted(a,key,m+1,r);
    }

    if(key>=a[m]&&key<=a[r])
           return  search_pivoted(a,key,m+1,r);
        else
           return search_pivoted(a,key,l,m-1);
}

void wrapper(int a[],int n,int key)
{
    int index=search_pivoted(a,key,0,n-1);

     if(index==-1)
        printf("element not found");
     else
        printf("element found at index:%d",index);
}

int main()
{
    int a[]={3,4,5,1,2};
    int n=sizeof(a)/sizeof(a[0]);
    int key=1;
    wrapper(a,n,key);
}
