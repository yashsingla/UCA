#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define r 3
#define c 3

int mini(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}

int min_cost(int a[r][c],int m,int n)
{
    if(m<0||n<0)
        return INT_MAX;
        else
    if(m==0&&n==0)
    return a[m][n];
   else
    return a[m][n] + mini(min_cost(a,m-1,n-1),min_cost(a,m,n-1),min_cost(a,m-1,n));
}

int main()
{
int a[r][c]={{1,2,3},
             {4,8,2},
             {1,5,3},
            };
int m=2,n=2;
 int x=min_cost(a,m,n);
printf("Mini_Cost:%d",x);
}
