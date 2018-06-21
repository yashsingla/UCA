#include<stdio.h>
#include<stdlib.h>

void printEvenOccuring(int a[],int n)
{
    long long _xor=0L;
    long long pos;

    int i;

    for(i=0;i<n;i++)
    {
        pos=1<<a[i];

        _xor^=pos;
    }

  for(i=0;i<n;i++)
    {
        pos=1<<a[i];

        if(!(_xor&pos))    //to find odd occuring elements:if((_xor & pos))
        {
            printf("%d\t",a[i]);
            _xor^=pos;
        }
    }

}

int main()
{
    //int a[]={1,4,7,5,9,7,3,4,6,8,3,0,3};
     int a[] = { 9, 12, 23, 10, 12, 12, 15, 23,
                 14, 12, 15 };
    int n=sizeof(a)/sizeof(a[0]);

    printEvenOccuring(a,n);
}
