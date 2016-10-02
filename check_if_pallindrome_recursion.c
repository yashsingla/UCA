#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int count(int n)
{
    int size=0;
    while(n>0)
    {
        size++;
        n=n/10;
    }
    return size;
}

int check_pallindrome(int n,int size)
{
    if(n<=0)
        return 1;

    int a=n/pow(10,size-1);
    int b=n%10;

     if(a==b)
     {
         n=n%(int)(pow(10,size-1));
         n=n/10;
         int size=count(n);
         check_pallindrome(n,size);
     }

     else
        return 0;

}



int main()
{
    int n=133,size=0;

       if(n<0)
        n=-n;

    size=count(n);
//printf("%d",size);
    int x=check_pallindrome(n,size);

    if(x)
        printf("n is Pallindrome");
    else
        printf("n is not Pallindrome");

}
