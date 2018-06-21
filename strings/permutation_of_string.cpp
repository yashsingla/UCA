#include<iostream>
#include<string.h>

using namespace std;

void fun(char a[],int used[],char temp[],int depth,int n)
{
    int i;

        if(depth==n)
        {
            temp[depth]='\0';
            cout<<temp<<endl;
            return;
        }
        else
        {
          for(i=0;i<n;i++)
         {

            if(used[i]==0)
            {
                used[i]=1;
                temp[depth]=a[i];
                fun(a,used,temp,depth+1,n);
                used[i]=0;
            }
         }
       }
}

int main()
{
    char a[]="abc";
    int n=strlen(a);
    int i,used[n];

    for(i=0;i<n;i++)
       used[i]=0;

    char temp[n];
    int depth=0;
    fun(a,used,temp,0,n);
}
