#include<stdio.h>
#include<stdlib.h>
int rand50()
{
    return rand();
}

int main()
{
   int i,x=2.5;
   for(i=1;i<=10;i++)
    printf("%d\n",rand50()%50);
printf("%d\n",x);
}
