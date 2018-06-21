#include<stdio.h>
#include<stdlib.h>
#define row 5
#define col 5

void dfs(int a[][col],int i,int j)
{
    a[i][j]=0;
    int l,m;
    if(i==0)
        l=i;
        else
          l=i-1;

    if(j==0)
        m=0;
    else
       m=j-1;


    while(l<=i+1&&l<row)
    { //outer while starts

        while(m<=j+1&& m<col)
        { //inner while starts

          if(l==i&&m==j)
            continue;

          if(a[l][m]==1)
            dfs(a,l,m);
              m++;

        }//inner while ends
        l++;

    }//outer while ends
    return;
}//function ends

int count_island(int m[][col])
{
    int i,j,count=0;
    int visited[row][col];

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(m[i][j]==1)
            {
                count++;
                dfs(m,i,j);
            }
        }
    }
    return count;
}

int main()
{
    int m[][col]={{1,1,0,0,0},
                   {0,1,0,0,1},
                   {1,0,0,1,1},
                   {0,0,0,0,0},
                   {1,0,1,0,1},
                 };
        int n=count_island(m);
        printf("no. of islands:%d",n);
}
