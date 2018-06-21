#include<iostream>
#include<string.h>

using namespace std;

void fun(char a[],int n)
{
    int i,j=0;

    for(i=1;i<=n;i++)
    {
        while(a[i]==a[j]&&j>=0)
        {
            i++;
            j--;
        }
        a[++j]=a[i];
    }
}

int main()
{
    //char a[]="abccbcba";
    char a[]="abbcckm";
    int n=strlen(a);
    fun(a,n);
    cout<<a;
}
