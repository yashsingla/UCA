#include<stdio.h>
#include<stdlib.h>

int fun(int a[4][4],int x,int n)
{
    if(x<a[0][0]||x>a[n-1][n-1])
        return 0;
    int i=0,j=0;

    while(i<n&&j<n)
    {
        if(x==a[i][j]|x==a[i][j+1]||x==a[i+1][j])
            return 1;

        if(x>a[i][j+1]&&x>a[j+1][i])
        {
            if(a[i][j+1]<a[i+1][j])
                j++;
            else
                i++;
        }
        else
            if(x>a[i][j+1])
            j++;
        else
            i++;
    }
    return 0;
}

int main()
{
    int m[4][4]={ {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
   if(fun(m,19,4))
       printf("Element is present in matrix");
   else
    printf("Element is not present in matrix");
}
