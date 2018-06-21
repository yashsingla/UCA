/*
time complexity:O(m+n);
Auxiliary Space : O(1)
ALGORITHM:
1) idea is to use hashing
2) take two auxilary arrays for two given arrays and store the frequency of each character in auxilary array using hashing
3)  we have 26 characters two arrays..so iterate through h1[] and h2[] and for any index i ..put ('a'+i) in result for
    min(h1[i],h2[i]) times
all permutation means result can be in any order: pink and kite gives result: "ik"... otherwise without all permutation it shuld be either "i" or "k"
 this can't be used instead of dynamic programming if we just want the count length of LCS but it wont guarantee the subsequence order like int above
 example if we go by this approach it will produce result "ik" which is wrong for LCS; subsequence is in same order ..as original sequence elements
*/

#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}

void lcs_permutations(char str1[],char str2[],int m,int n)
{
    char h1[26]={0};
    char h2[26]={0};
    char result[10];
    int i,j,k=0;

   for(i=0;i<m;i++)
    h1[str1[i]-'a']++;

   for(i=0;i<n;i++)
  h2[str2[i]-'a']++;

  for(i=0;i<26;i++){
    for(j=1;j<=min(h1[i],h2[i]);j++){
        result[k]='a'+i;
            k++;
    }
    }
    result[k]='\0';
  printf("result:%s",result);
}

int main()
{
    char str1[]="pink";
    char str2[]="kite";
    int m=sizeof(str1)/sizeof(str1[0]);
    int n=sizeof(str2)/sizeof(str2[0]);
     printf("str1:%s\n",str1);
     printf("str2:%s\n",str2);

   lcs_permutations(str1,str2,m,n);
}
