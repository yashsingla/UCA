#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int mini(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int min_jump(int a[],int n)
{
    if(a[0]==0)
        return INT_MAX;
    int *count=(int *)malloc(sizeof(int)*n);

     count[0]=0;
     int i,j;

     for(i=1;i<n;i++)
     {
         for(j=0;j<i;j++)
         {
             if(i<=j+a[j]){
                count[i]=mini(count[i],count[j]+1);
             break;
             }
         }
     }
return count[n-1];
}

int main()
{
    int a[]={1, 3, 6, 1, 0, 9};
    int n=sizeof(a)/sizeof(a[0]);
    int x=min_jump(a,n);
    if(x==INT_MAX)
    printf("cannot reach end of array");
    else
    printf("minimum number of jumps required :%d",x);
}
