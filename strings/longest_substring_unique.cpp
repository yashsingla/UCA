// O(n^2) time complexitys
#include<iostream>
#include<string.h>
#include<limits.h>

using namespace std;

int fun(char str[],int n)
{
    int i=0,j=0;
    int m[26]={0},maxi=INT_MIN;

   while(i<n)
   {
       if(m[str[i]-'a']==0){
        m[str[i]-'a']++;
         i++;
       }
       else if(i+1!=n)
       {
           if(i-j>maxi)
            maxi=i-j;

           while(m[str[i]-'a']!=0)
               m[str[j++]-'a']--;
       }
       else break;
   }//main while ends

  if(i-j>maxi)
    maxi=i-j;

return maxi;
} // fun ends

int main()
{
    //char str[]="geeksforgeeks";
    char str[]="aaaaaaab";
    int n=strlen(str);

    cout<<"length:"<<fun(str,n);
}
