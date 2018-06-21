/*
Algorithm:
1. I will take a structure to store X and Y index of element in 2d matrix
2. I will find the indexes of occurence first character of pattern and store it in structure
3. With every index of first character of pattern, i will search for pattern in 2d matrix using dfs
*/
#include<iostream>
#include<string.h>
#include<map>
#define r 5
#define c 5

using namespace std;

struct index
{
    int i,j;
};

int fun(char a[r][c],char p[],int l,int n,int i,int j,int temp[r][c])
{
        cout<<i<<" "<<j<<endl;
       temp[i][j]=1;
      if(l==(n-1))
        return 1;


       int b=0;
       if(i>=1&&j>=1&&(a[i-1][j-1]==p[l+1])&&temp[i-1][j-1]==0 )   // top left corner
             b=fun(a,p,l+1,n,i-1,j-1,temp);
else
       if(i>=1&&j<c&& (a[i-1][j]==p[l+1])&&temp[i-1][j]==0 )        // top middle
        b=fun(a,p,l+1,n,i-1,j,temp);
else
        if(i>=1&&j<c&& (a[i-1][j+1]==p[l+1])&&temp[i-1][j+1]==0 )        // top right corner
        b=fun(a,p,l+1,n,i-1,j+1,temp);
else
        if(i<r&&j>=1&& (a[i][j-1]==p[l+1])&&temp[i][j-1]==0 )        // middle left
        b=fun(a,p,l+1,n,i,j-1,temp);
else
       if(i<r&&j<c&& (a[i][j+1]==p[l+1])&&temp[i][j+1]==0 )        //  middle right
        b=fun(a,p,l+1,n,i,j+1,temp);
else
        if(i<r&&j>=1&& (a[i+1][j-1]==p[l+1])&&temp[i+1][j-1]==0 )        // bottom left
        b=fun(a,p,l+1,n,i+1,j-1,temp);
else
        if(i<r&&j<c&& (a[i+1][j]==p[l+1])&&temp[i+1][j]==0 )        // bottom middle
        b=fun(a,p,l+1,n,i+1,j,temp);
else
        if(i<r&&j<c&& (a[i+1][j+1]==p[l+1])&&temp[i+1][j+1]==0 )        // bottom right
        b=fun(a,p,l+1,n,i+1,j+1,temp);


    temp[i][j]=0;
    return b;
}

void wrapper(char a[r][c],char p[],int n)
{
    struct index obj[5];
   int cnt=0,i,j;
//-----------------------------------
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)
       {
           if( a[i][j]==p[0] )
           {
               obj[cnt].i=i;
               obj[cnt].j=j;
               cnt++;
           }
       }
   }
//-------------------------------
int k,l=0,temp[r][c]={0},y=0;

for(k=0;k<cnt;k++)
{

    int i=obj[k].i;

    int j=obj[k].j;

    if(fun(a,p,l,n,i,j,temp))
    { y=1;
    cout<<"pattern found";
    break;
    }
}
if(y==0)
cout<<"pattern not found";
}// funtion ends


int main()
{
    char a[r][c]={{'a','c','p','r','c'},
                  {'x','s','o','p','c'},
                  {'v','o','v','n','i'},
                  {'w','g','f','m','n'},
                  {'q','a','t','i','ma'}};

      char p[]="microsoft";
      int n=strlen(p);

      wrapper(a,p,n);
}
