#include<stdio.h>
#include<stdlib.h>

int allAre9s(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]!=9)
        return 0;
    return 1;
}

void generateNext(int a[],int n)
{
    int mid=n/2;

    int i=mid-1;

    int j=(n%2)?mid+1:mid;

    int smallLeft=0;

    while(i>=0&&a[i]==a[j])
        i--,j++;

    if(i<0||a[i]<a[j]) // i<0 only if number is pallindrome
        smallLeft=1;

    while(i>=0)
    a[j++]=a[i--];

    if(smallLeft==1)
    {
        int carry=1;
         i=mid-1;

        if(n%2==1)
        {
            a[mid]+=carry;
            carry=a[mid]/10;
            a[mid]%=10;
            j=mid+1;
        }
        else
            j=mid;

   // this while is mainly if we have 9 in the middle
    while(i>=0)
    {
        a[i]+=carry;
        carry=a[i]/10;
        a[i]%=10;
        a[j++]=a[i--];
    }
  }
}

void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
      printf("%d ",a[i]);
}

void wrapper(int a[],int n)
{
    int i;
    if(allAre9s(a,n))
    {
        printf("1");
        for(i=1;i<n;i++)
            printf("0");
        printf("1");
    }
    else
    {
        generateNext(a,n);
        print(a,n);
    }
}

int main()
{
    int a[]={9,4,1,8,7,9,7,8,3,2,3};
    int n=sizeof(a)/sizeof(a[0]);
    wrapper(a,n);
}
