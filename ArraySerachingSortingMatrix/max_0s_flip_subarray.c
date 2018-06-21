#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int fun(int a[],int n)
{
    int max=INT_MIN;
    int max_till_now=INT_MIN;
    int i;
int count_zero=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==0){
            max=0;
        count_zero++;
        }
        else
            max=max+a[i];

    if(max>max_till_now)
      max_till_now=max;
   }
   return max_till_now+count_zero;
}

int main()
{
    //int a[]={0,0,0,1,0,1};
    int a[]={0,1,0,0,1,1,0};
    int n=sizeof(a)/sizeof(a[0]);

    int x=fun(a,n);
    printf("maximum 0s with one flip:%d",x);
}
