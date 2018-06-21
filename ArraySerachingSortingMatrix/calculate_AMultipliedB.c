//calculate a*b%m

#include<stdio.h>
#include<stdlib.h>


// this log(b) solution with calling fun(a,b/2) only once
int fun(int a,int b)
{
    if(b==0)
    {
        return 0;
    }

   int result=fun(a,b/2);

    if(b%2==0)
    return result+result;
    else
        return a+result+result;
}

int main()
{
    int a=-2,b=11;

       if(a<0) //covering negative cases
        a=-a;
    int x=fun(a,b);

    if(b%2)
        x=-x;

    printf("result:%d",x);
}
