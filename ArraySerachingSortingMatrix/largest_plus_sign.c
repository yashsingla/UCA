#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define r 5
#define c 5

// this code is little inefficient as we are calculating consecutive 1's every time for every value of (i,j)

void hor_left(int a[][c],int i,int j, int *x1)
{
          if(a[i][j-1]==1)
          {
              (*x1)++;
              hor_left(a,i,j-1,x1);
          }
          else
            return;
}

void hor_right(int a[][c],int i,int j, int *x)
{
          if(a[i][j+1]==1)
          {
              (*x)++;
              hor_right(a,i,j+1,x);
          }
          else
            return;
}

void vert_top(int a[][c],int i,int j, int *y)
{
          if(a[i-1][j]==1)
          {
              (*y)++;
              vert_top(a,i-1,j,y);
          }
          else
            return;
}

void vert_bottom(int a[][c],int i,int j, int *y1)
{
          if(a[i+1][j]==1)
          {
              (*y1)++;
              vert_bottom(a,i+1,j,y1);
          }
          else
            return;
}

int min(int a,int b)
{
   return a<b?a:b;
}

int maxi(int a,int b)
{
   return a>b?a:b;
}

int largestPlus(int a[r][c])
{
    int i=0,j=0,max=INT_MIN,size;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {  size=0;
            if(a[i][j]==1)
            {
                if(a[i+1][j]==1 &&
                   a[i-1][j]==1 &&
                   a[i][j+1]==1 &&
                   a[i][j-1]==1
                  )
                {
                    size++;
                    int x=0,x1=0,y=0,y1=0;
                    hor_left(a,i,j-1,&x1);
                    hor_right(a,i,j+1,&x);
                    vert_top(a,i-1,j,&y);
                    vert_bottom(a,i+1,j,&y1);

                    size+=maxi(min(x,x1),min(y,y1));
                }  //inner if ends
              if(size>max)
                max=size;
            }//outer if ends
        }//inner for ends
    }//outer for ends
    return max;
}//function ends

int main()
{
    int a[5][5]={{0,1,0,0,0},
                 {1,1,1,0,0},
                 {1,1,1,1,0},
                 {0,1,1,0,0},
                 {0,1,0,0,0}
                };

      int x=largestPlus(a);
      if(x!=INT_MIN)
      printf("maximum:%d",x);
      else
        printf("0");
}
