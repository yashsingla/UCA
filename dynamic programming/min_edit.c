#include<stdio.h>

int minimum(int a,int b,int c)
{
    if(a<b)
        if(a<c)
        return a;
    else
        return c;

    if(b<c)
        return b;
    else
        return c;
}

int min_edit(char str1[],char str2[],int m,int n)
{  int i,j,d[m+1][n+1];
    //if(m==0)
      //  return n;

    //if(n==0)
   //return m;

/*
   for(i=0;i<=n;i++)
    d[i][0]=i;

   for(j=0;j<=m;j++)
    d[0][j]=j;
*/
  for(i=0;i<=m;i++)
  {
      for(j=0;j<=n;j++)
      {
          if(i==0)
            d[i][j]=j;
            else
          if(j==0)
          d[i][j]=i;
          else

       if(str1[i-1]==str2[j-1])
          d[i][j]=d[i-1][j-1];


       else
        d[i][j]=1+minimum(d[i-1][j-1],d[i-1][j],d[i][j-1]);


     }//inner for
  }//outer for

return d[m][n];
}


int main()
{
    char str1[]="sunday";
    char str2[]="saturday";

    int x=strlen(str1);
    int y=strlen(str2);

    int min=min_edit(str1,str2,x,y);
    printf("%d",min);
}
