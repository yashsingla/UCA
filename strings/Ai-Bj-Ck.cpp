#include<iostream>
#include<string>

using namespace std;

int fun(string s)
{
    int n=s.size();
    int aCount=0,bCount=0,cCount=0;
   int i;

   for(i=0;i<n;i++)
   {
       if(s[i]=='a')
        aCount=1+2*aCount;

      else

        if(s[i]=='b')
        bCount=aCount+2*bCount;

      else

     if(s[i]=='c')
        cCount=bCount+2*cCount;
   }
return cCount;
}

int main()
{
    string s="abbc";

    cout<<"number:"<<fun(s);
}
