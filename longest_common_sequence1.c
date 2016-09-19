#include<stdio.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int lcs(char x[],char y[],int m,int n)
{  int l[m][n],i,j;

    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
                l[i][j]=0;
             else
            if(x[i-1]==y[j-1])
            {
                l[i][j]=1+l[i-1][j-1];
            }
            else
            {
                l[i][j]=max(l[i-1][j],l[i][j-1]);
            }

        }//inner for
    }//outer for
    return l[m][n];
}//function end


int main()
{
    char x[]="AeBqCWK";
    char y[]="ABCedWK";

    int m=strlen(x);
    int n=strlen(y);

   int z=lcs(x,y,m,n);
  printf("Length:%d",z);

}
