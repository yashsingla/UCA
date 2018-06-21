#include<stdio.h>
#include<stdlib.h>
#define n 4

void anti_clock(int a[][n])
{
    int i,j;

    for(i=0;i<n/2;i++)
    {
        for(j=i;j<n-i-1;j++)
        {
            int temp=a[i][j];
            a[i][j]=a[j][n-i-1];
            a[j][n-i-1]=a[n-i-1][n-j-1];
            a[n-i-1][n-j-1]=a[n-j-1][i];
            a[n-j-1][i]=temp;
        }//inner for ends
    }//outer for ends

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            {
                printf("%d ",a[i][j]);

            }
            printf("\n");
    }
}//anti_clock function ends

void clock_wise(int a[][n])
{
    int i,j;

    for(i=0;i<n/2;i++)
    {
        for(j=i;j<n-i-1;j++)
        {

            int temp=a[n-j-1][i];
            a[n-j-1][i]=a[n-i-1][n-j-1];
            a[n-i-1][n-j-1]=a[j][n-i-1];
            a[j][n-i-1]=a[i][j];
            a[i][j]=temp;

        }//inner for ends
    }//outer for ends

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
    }
}//clock_wise function ends


int main()
{
    int a[][4]={ {1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16},
              };

    //anti_clock(a);
    clock_wise(a);
}
