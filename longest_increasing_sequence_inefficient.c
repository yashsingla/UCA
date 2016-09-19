#include<stdio.h>

int main()
{
  signed int a[]={3,4,-1,0,6,2,3};
     int n=sizeof(a)/sizeof(a[0]);
     printf("n:%d\n",n);
     int b[n];
int i,j;
     for(i=0;i<=n;i++)
        b[i]=1;


     for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j]&&a[j]>a[j-1])
                {b[i]=b[i]+1;
                printf("%d\t",a[j]);
        }}
        printf("\n");
    }

    int max=b[0];
    for(i=1;i<n;i++)
    {
        if(b[i]>max)
            max=b[i];
    }

    printf("max:%d",max);

}
