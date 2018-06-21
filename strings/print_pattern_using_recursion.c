#include<stdio.h>
#include<stdlib.h>

void pattern(int n)
{
    if(n==0||n<0)
    {
        printf("%d\t",n);
        return;
    }

    printf("%d\t",n);
    pattern(n-5);

printf("%d\t",n);

}

int main()
{
    int n=16;
    pattern(n);
}
