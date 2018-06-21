#include<stdio.h>
#include<stdlib.h>

int fun(int x,int y)
{
    int m,n,count_x=0,count_y=0;

    while(1){
            m=x,n=y;
    while(n)
    {
        int b_y=n&1;
        count_y++;
         n=n>>1;
    }

    while(n)
    {
        int b_y=x&1;
        count_x++;
         x=x>>1;
    }

    }
}

int main()
{  //x<=y always,given in question,range is x to y
    int x=10,y=15;
    int result=fun(x,y);
    printf("result:%d",result);
}
