#include<stdio.h>
#include<stdlib.h>

// time complexity: O(suqare root of X)
int fun(int x)
{
    if(x==0||x==1)
        return x;

    int i,result;
    for(i=1;i*i<=x;i++)
       result=i;
return result;
}

//using binary search ..time complexity: O(logX)
int fun1(int x)
{
    if(x==0||x==1)
        return x;

    int start=0,end=x/2; //square root wont be greater than x/2..in interview start your approach with end=x..then reduce
                          // x to x/2;
    int result;

    while(start<=end)
    {
      int m=(start+end)/2;

      if(m*m==x)
        return m;

      if(m*m<x)
      {
          start=m+1;
          result=m;
    }
    else
        end=m-1;
    }

return result;
}

int main()
{
    int x=10;
    printf("Floor square root:%d",fun1(x));
}
