//time complexity: O(logN)
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void lower_bound(int l,int r,int a[],int key,int *lower)
{
   if(l>r)
    return ;

  int m=(l+r)/2;

   if(a[m]==key)
   {
       if(m<(*lower))
        (*lower)=m;
   }

   if(key<=a[m])
    lower_bound(l,m-1,a,key,lower);
   else
   lower_bound(m+1,r,a,key,lower);
}

void upper_bound(int l,int r,int a[],int key,int *upper)
{
   if(l>r)
    return ;

  int m=(l+r)/2;

   if(a[m]==key)
   {
       if(m>(*upper))
        (*upper)=m;
   }

   if(key>=a[m])
    upper_bound(m+1,r,a,key,upper);
   else
   upper_bound(l,m-1,a,key,upper);
}


void wrapper(int a[],int n,int key)
{
    int lower=INT_MAX;
    lower_bound(0,n-1,a,key,&lower);

    int upper=INT_MIN;
    upper_bound(0,n-1,a,key,&upper);

  printf("count:%d",upper-lower+1);
}

int main()
{
    //int a[]={1,1,2,2,2,2,2,2};
    int a[]={1,1,2,2,2};
    int n=sizeof(a)/sizeof(a[0]);

    wrapper(a,n,2);
}
