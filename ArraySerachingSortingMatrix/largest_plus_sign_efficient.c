//time complexity:O(r*c)
//space complexity:O(r*c)

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define r 5
#define c 5

int min(int a,int b)
{
   return a<b?a:b;
}


int largestPlus(int mat[r][c])
{
    int i,j;
    int left[r][c],right[r][c],top[r][c],bottom[r][c];

   for(i=0;i<r;i++)
   {
       left[i][0]=mat[i][0];

       right[i][r-1]=mat[i][r-1];

       top[0][r-1]=mat[0][r-1];

       bottom[r-1][i]=mat[r-1][i];
   }


    for(i=0;i<r;i++)
    {
        for(j=1;j<c;j++)
        {
            if(mat[i][j]==1)
                left[i][j]=left[i-1][j]+1;
                else
                    left[i][j]=0;

            if(mat[j][i]==1)
                top[j][i]=top[j][i-1]+1;
                else
                    top[i][j]=0;

            j=c-j-1;

            if(mat[j][i]==1)
                bottom[j][i]=bottom[j+1][i]+1;
                else
                    bottom[i][j]=0;

           if(mat[i][j]==1)
                right[i][j]=right[i][j+1]+1;
                else
                    right[i][j]=0;
         j=c-j-1;
        }//inner for ends
    }//outer for ends

   int n=0;
    for(i=0;i<r;i++){
      for(j=0;j<c;j++)
    {
         int len=min(min(top[i][j],bottom[i][j]),min(left[i][j],right[i][j]));
         if(len>n)
            n=len;
    }
  }

   if(n)
    return 4*(n-1)+1;
  return 0;
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
      printf("maximum:%d",x);
}
