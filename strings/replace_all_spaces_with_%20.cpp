#include<iostream>
#include<string.h>

using namespace std;

void fun(char a[],int n)
{
    int i,s=0;

    for(i=0;i<n;i++)
      if(a[i]==' '||a[i]=='\t')
         s++;

    if(s==0)
     return;

    int new_len=n+s*2;

    for(i=n-1;i>=0;i--)
    {
        if(a[i]==' '||a[i]=='\t')
        {
            a[new_len--]='0';
            a[new_len--]='2';
            a[new_len--]='%';
        }
        else
        {
            a[new_len--]=a[i];
        }
    }
cout<<a;
}

int main()
{
    char a[]="my name is yash";
    int n=strlen(a);
    fun(a,n);
}
