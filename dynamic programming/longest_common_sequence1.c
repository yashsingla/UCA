//, a subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the
//remaining elements. For example, the sequence { A,B,D}   is a subsequence of { A,B,C,D,E,F}

//time complexity:O(m*n)
//space complexity:O(m*n);
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
    char x[]="AGGTAB";//"AeBqCWK";
    char y[]="GXTXAYB";//"ABCedWK";

    int m=strlen(x);
    int n=strlen(y);

   int z=lcs(x,y,m,n);
  printf("Length:%d",z);

}
/*
recursive
int fun(string s1,string s2,int n1,int n2)
{
    if(n1==0||n2==0)
        return 0;

    if(s1[n1-1]==s2[n2-1])
        return 1+fun(s1,s2,n1-1,n2-1);
    else
      return maxi(fun(s1,s2,n1,n2-1),fun(s1,s2,n1-1,n2));
}

*/
