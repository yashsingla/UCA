#include<stdio.h>
#include<stdlib.h>
#define r 3
#define c 4

void fun(int a[][c],int i,int j)
{
    a[i][j]=2;

           if(i>0&&a[i-1][j]==1)
                fun(a,i-1,j);


              if(i<r&&a[i+1][j]==1)
                 fun(a,i+1,j);


              if(j>0&&a[i][j-1]==1)
                 fun(a,i,j-1);


              if(j<c&&a[i][j+1]==1)
                  fun(a,i,j+1);
}

int min_rot(int a[][c])
{
    int sum=0,k,i,j;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            k=0;
          if(a[i][j]==2)
          {
              if(i>0&&a[i-1][j]==1)
              {  k=1;
                fun(a,i-1,j);
              }

              if((i+1)<r&&a[i+1][j]==1)
              {  k=1;
                fun(a,i+1,j);
              }

              if(j>0&&a[i][j-1]==1)
              {  k=1;
                fun(a,i,j-1);
              }

              if((j+1)<c&&a[i][j+1]==1)
              {  k=1;
                fun(a,i,j+1);
              }
          }//main if ends
            if(k==1)
                sum++;
      }//inner for ends
    }//outer for ends

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]==1)
                sum = -1;
        }
    }
    return sum;
}//function ends

int main()
{
    int a[r][c]={ {2,1,0,2,1},
                  {1,0,1,2,1},
                  {1,0,0,2,1}
                };

   /* int a[r][c]={{2,1,0,2,1},
                  {0,0,1,2,1},
                  {1,0,0,2,1}
                };
*/
   int x=min_rot(a);
     if(x==-1)
        printf("all oranges cant be rotten");
     else
        printf("time taken:%d",x);
}
