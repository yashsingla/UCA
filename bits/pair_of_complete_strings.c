#include<stdio.h>
#include<stdlib.h>

int pair(char set1[][20],char set2[][20],int m,int n)
{
    int freq[26]={0};
    int i,j,k,result=0;

    for(i=0;i<m;i++)
    {
      int size=sizeof(set1[i])/sizeof(set1[i][0]);

      for(j=0;j<n;j++)
        {
           freq[26]={0};

           for(k=0;k<size;k++)
         freq[set1[i][k]-'a']++;

     for(k=0;k<size;k++)
         freq[set1[j][k]-'a']++;

    for(k=0;k<26;k++)
         if(freq[k]<1)
            break;
         if(k==26)
            result++;

      }//inner for
   }//main for ends
 return result;
}//function ends

int main()
{
    char set1[][20]={"abcdefgh", "geeksforgeeks" , "lmnopqrst", "abc"};
    char set2[][20]={"ijklmnopqrstuvwxyz","abcdefghijklmnopqrstuvwxyz","defghijklmnopqrstuvwxyz"};

    int m=sizeof(set1)/sizeof(set1[0]);
    int n=sizeof(set2)/sizeof(set2[0]);

  printf("result:%d\n",pair(set1,set2,m,n));
}
