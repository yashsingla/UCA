#include<stdio.h>
#include<stdlib.h>

int sum(int a,int b)
{return a+b;}

int sub(int a,int b)
{return a-b;}

int multiply(int a,int b)
{return a*b;}

int wrapper(int (*fun)(int ,int ),int a,int b)
{return fun(a,b);}

int main()
{
    int sum=wrapper(sum,2,3);
    int sub=wrapper(sub,2,3);
    int mul=wrapper(multiply,2,3);
    printf("sum:%d\nsub:%d\nmul:%d\n",sum,sub,mul);
}
