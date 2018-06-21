#include<iostream>
#include<string.h>

using namespace std;

void fun(char a[],char b[],int a1,int b1,char s[],int i,int j,int k)
{
    if(i==a1&&j==b1){
    cout<<s<<endl;
      return;
    }

if(i!=a1)
{
    s[k]=a[i];
    fun(a,b,a1,b1,s,i+1,j,k+1);
}

if(j!=b1)
{
    s[k]=b[j];
    fun(a,b,a1,b1,s,i,j+1,k+1);
}
}

int main()
{
    char a[]="AB";
    char b[]="CD";
    int a1=strlen(a);
    int b1=strlen(b);
    char s[a1+b1];
    fun(a,b,a1,b1,s,0,0,0);
}
