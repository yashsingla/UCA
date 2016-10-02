#include<stdio.h>
#include<stdlib.h>

int fib(int n,int *fp)
{
    if(n<=1)
    {
      *fp=1;
      return 1;
    }
    int t=fib(n-1,fp);
    int f=t+*fp;
    *fp=t;

    return f;
}

/*statement t = fun ( n-1, fp ) gives the (n-1)th Fibonacci number and *fp is used to store the (n-2)th Fibonacci Number.
Initial value of *fp (which is 15 in the above prgram) doesn’t matter. */

int main()
{
    int x=15;  //(here x doesnt matter..can be anything`)
    printf("%d",fib(5,&x));
}
