#include<stdio.h>
#include<stdlib.h>

void twoMissing(int a[],int n)
{
    int i,x=0;

    for(i=1;i<=n;i++)
        x=x^i;
    for(i=0;i<(n-2);i++)
        x=x^a[i];

    int set_bit=x&(~(x-1));

    int m=0,k=0;

    for(i=1;i<=n;i++)
       {
           if(i&set_bit)
        m=m^i;
    else
        k=k^i;
       }

    for(i=0;i<(n-2);i++){
        if(a[i]&set_bit)
        m=m^a[i];
    else
        k=k^a[i];
    }


      printf("m:%d\nk:%d",m,k);
}

int main()
{
    int a[]={1,3,5,6};
    int n=sizeof(a)/sizeof(a[0])+2;

    twoMissing(a,n);
}
