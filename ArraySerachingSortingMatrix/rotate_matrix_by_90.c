#include<stdio.h>
#include<stdlib.h>
#define r 3
#define c 3

void fun(int a[][c])
{

    int temp[r][c];
    int l=0,m,i,j;
    /*//rotate anti-clock wise by 90 degree
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            temp[i][j]=a[j][r-1-i];
        }

    }*/

   //rotate clock wise to 90 degree
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            temp[i][j]=a[r-1-j][i];
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",temp[i][j]);

        }
        printf("\n");
    }

}


int main()
{
    int a[r][c]={ {1,2,3},
                   {4,5,6},
                   {7,8,9}};

    fun(a);
    int i,j;

}
