#include<stdio.h>

int main()
{
    int n=15,count=0;

    while(n)
    {
        count+=n&1;
        n>>=1;

    }
                                    //complexity: theta(logN)
    printf("%d",count);
}
/*

while(n)
{

n=n&(n-1);
count++;                        complexity:O(logN)

}
*/
