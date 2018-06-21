#include<stdio.h>
#include<stdlib.h>

void fun(int a[],int key,int l,int r,int *p)
{
    if(l>r)
        return;

    int m=(l+r)/2;

    if(a[m]==key)
        (*p)++;


    fun(a,key,l,m-1,p);

    fun(a,key,m+1,r,p);
}

int main()
{
    int a[]={1,1,1,1,2,3,4,4,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    int key=1;
    int p=0;
    fun(a,key,0,n-1,&p);
    printf("count:%d",p);
}
