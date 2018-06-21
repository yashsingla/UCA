//calculate a*b
#include<stdio.h>
#include<stdlib.h>

// this log(b) solution with calling fun(a,b/2) only once
float fun(float a,int b)
{
    if(b==0)
    {
        return 1;
    }

   float result=fun(a,b/2);

    if(b%2==0)
    return result*result;
    else{
            if(b>0)
        return result*result*a;
       else
       return (result*result)/a;
    }
}

int main()
{
    float a=2;
    int b=-3;


    float x=fun(a,b);

    printf("result:%3f",x);
}


