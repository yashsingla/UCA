#include<iostream>
#include<string>

using namespace std;

void ReverseString(char a[],int x,int y)
{

    while(x<y)
    {
        char temp=a[y];
        a[y]=a[x];
        a[x]=temp;
        x++;
        y--;
    }
}

void fun(char a[],int n)
{
    ReverseString(a,0,n-1);

    int k;
    int i;

    for(i=0;i<n;i++)
    {
        if(a[i]!=' ')
        {
            k=i;

         while(a[i++]!=' '&&i<n);
           i=i-1;

        ReverseString(a,k,i);
        }
    }

    for(i=0;i<n;i++)
        cout<<a[i];
}

int main()
{
    char a[]="string monk career a is this";
    int n=sizeof(a)/sizeof(a[0]);

    fun(a,n);
}
