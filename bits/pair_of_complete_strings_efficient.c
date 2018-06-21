#include<stdio.h>
#include<stdlib.h>

int pair(char set1[],char set2[],int m,int n)
{
 long long int a1[m];
 long long  int a2[n];
    int i,j,x,y;
    int result=0;

    for(i=0;i<m;i++)
    {int size=sizeof(set1[i])/sizeof(char);
       a1[i]=0;
     for(j=0;j<size;j++){
      a1[i]=(a1[i])|(1<<(set1[i][j]-'a'));
    }}

    for(i=0;i<n;i++)
    {int size=sizeof(set2[i])/sizeof(char);
        a2[i]=0;
      for(j=0;j<size;j++)
      a2[i]=a2[i]|(1<<(set2[i][j]-'a'));
    }

  long long c=(1<<26) - 1;
  for(i=0;i<m;i++)
  {
      for(j=0;j<n;j++)
      { long long temp=a1[i]|a2[j];
          if(temp==c)
            result++;
      }
  }
return result;
}//function ends

int main()
{
    char set1[]={"abcdefgh", "geeksforgeeks" , "lmnopqrst", "abc"};
    char set2[]={"ijklmnopqrstuvwxyz","abcdefghijklmnopqrstuvwxyz","defghijklmnopqrstuvwxyz"};

    int m=sizeof(set1)/sizeof(set1[0]);
    int n=sizeof(set2)/sizeof(set2[0]);

  printf("result:%d\n",pair(set1,set2,m,n));
}

