//calculate a^b
#include<stdio.h>
#include<stdlib.h>


// this log(b) solution with calling fun(a,b/2) only once
int fun(int a,int b)
{
    if(b==0)
    {
        return 1;
    }

   int result=fun(a,b/2);

    if(b%2==0)
    return result*result;
    else
        return a*result*result;
}

int main()
{
    int a=2,b=11;

    int x=fun(a,b);

    printf("result:%d",x);
}

