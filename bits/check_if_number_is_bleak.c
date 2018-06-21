//A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any
// non-negative number x.

//Algorithm:The idea is based on the fact that the largest count of set bits in any number smaller than n cannot exceed
//ceiling of Log2n. So we need to check only numbers from range n – ceilingLog2(n) to n.

#include<stdio.h>
#include<stdlib.h>

int setBits(int n)
{
    if(n<1)
        return 0;
        int c=0;
    while(n)
    {
        n=n&(n-1);
        c++;
    }
    return c;
}

int LogCeil(int n)
{
    n--;
    int c=0;
    while(n)
    {
        n=n>>1;
        c++;

    }
    return c;
}

int isBleak(int n)
{
    int i;
    for(i=n-LogCeil(n);i<n;i++)
        if(i+setBits(i)==n)
           return 0;
    return 1;
}

int main()
{
    isBleak(3)?printf("3 is bleak\n"):printf("3 is not bleak\n");
    isBleak(4)?printf("4 is bleak\n"):printf("4 is not bleak\n");
}
