#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//solution-1::kadane's algorithm
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        if(b>a)
        return b;
    else
        return a;
}
/*int max_sum(int a[],int n)
{
    int max_end=0,max_so_far=INT_MIN;
int i;
    for(i=0;i<n;i++)
    {
        max_end=a[i]+max_end;
        if(max_so_far<max_end)
            max_so_far=max_end;

        if(max_end<0)
            max_end=0;
    }
return max_so_far;
}*/

//solution-2
int max_sum(int a[],int n)
{
    int cur_max=0,max_so_far=INT_MIN;
int i;
    for(i=0;i<n;i++)
    {
        cur_max=max(a[i],a[i]+cur_max);
        max_so_far=max(cur_max,max_so_far);
    }
return max_so_far;
}

int main()
{
    //int a[]={-2,-3,4,-1,-2,1,5,-3};
    int a[]={-2,-3,-4,-1,-2,-1,-5,-3};
    int n=sizeof(a)/sizeof(a[0]);
    int result=max_sum(a,n);
printf("maximum sum of contiguous subarray:%d",result);
}
