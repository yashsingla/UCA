#include<iostream>
#include<string>
#include<cstring>

using namespace std;

void reArrange(string str,int k)
{
    /*  >>one solution
    int n=str.size();
    int i,j;

    for(i=0;i<k;i++)
    {
        //char a=str[i];
         str.push_back(str[i]);
  }
   for(i=k;i<str.size();i++)
     str[i-k]=str[i];

   for(i=0;i<k;i++)
     str[n+i]='\0';
     */
     //>> second solution
    str.append(str,0,k);
    str.erase(str.begin(),str.begin()+k);
    //str.erase(str.begin()+3); jus for practice
    cout<<str;
}

int main()
{
    string a="abcdef";
    int k=4;
    reArrange(a,k);
}
