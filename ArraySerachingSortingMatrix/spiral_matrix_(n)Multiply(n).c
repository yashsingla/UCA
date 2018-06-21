#include<stdio.h>
#include<stdlib.h>
#define n 3

void fun(int a[][n])
{
    int i,j;

    for(i=0;i<=n/2;i++)
    {
        for(j=i;j<=n-i-1;j++)
        printf("%d ",a[i][j]);

        for(j=i+1;j<n-i;j++)
        printf("%d ",a[j][n-i-1]);

        for(j=n-i-2;j>=i;j--)
        printf("%d ",a[n-i-1][j]);

        for(j=n-i-2;j>i;j--)
        printf("%d ",a[j][i]);

    }//outer for ends
}

int main()
{
    int a1[][n]={ {1,2,3,4,5},
                 {6,7,8,9,10},
                 {11,12,13,14,15},
                 {16,17,18,19,20},
                 {21,22,23,24,25}
               };

    int a2[][n]={ {1,2,3,4},
                 {5,6,7,8},
                 {9,10,11,12},
                 {13,14,15,16}
                 };

  int a[][n]={ {1,2,3},
                 {4,5,6},
                 {7,8,9} };


             fun(a);
}
