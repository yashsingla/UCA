#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *p,x=100,y=200;
    p=&x;
    printf("%d\n",*p);
    *p=y;
    printf("%d",x);
}
