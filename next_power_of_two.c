#include<stdio.h>

int is_power_of_two(int n)
{
    return (n+1)&&(!((n+1)&n));
}
int main()
{
    int n=4;
     //int x=n-1;
    while(!(is_power_of_two(n-1)))
    {
        n++;
    }

    printf("next power of two:%d",n);
}
