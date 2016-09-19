#include<stdio.h>

int main()
{
    int a[]={3,4,-1,0,6,2,3};
    int n=sizeof(a)/sizeof(a[0]);
    int b[n];
    int i,j;

    for(i=0;i<n;i++)
        b[i]=1;

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j]&&b[i]<b[j]+1)
                b[i]=b[j]+1;
        }
    }
    int max=0;

    for(i=0;i<n;i++)
        if(b[i]>max)
        max=b[i];

    printf("Max_Length:%d",max);

}
