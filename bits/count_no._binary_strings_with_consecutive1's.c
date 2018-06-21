//time complexity:O(n)
#include<stdio.h>
#include<stdlib.h>

int count(int n)
{
    int a[n],b[n];
    a[0]=b[0]=1;
    int i;
    for(i=1;i<=n;i++)
    {
        a[i]=a[i-1]+b[i-1];
        b[i]=a[i-1];
    }
    return (1<<n)-a[n-1]-b[n-1]; //return a[n-1]+b[n-1] for counting no. of binary strings wihtout consecutive 1's for given binary
}                                //length of size n or other solution if n+2th fibonacci number

int main()
{
    int n=5;
    int k=count(n);
  printf("count:%d",k);
}

/* solution using fibonacci series:-

If we take a closer look at the pattern of counting strings without consecutive 1’s, we can observe that the count is actually
(n+2)’th Fibonacci number for n >= 1. The Fibonacci Numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 141, ….

n = 1, count = 0  = pow(2,1) - fib(3)
n = 2, count = 1  = pow(2,2) - fib(4)
n = 3, count = 3  = pow(2,3) - fib(5)
n = 4, count = 8  = pow(2,4) - fib(6)
n = 5, count = 19 = pow(2,5) - fib(7)
*/
