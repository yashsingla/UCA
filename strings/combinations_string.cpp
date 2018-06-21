#include<iostream>
#include<string.h>
#include<map>

using namespace std;

void fun(char a[],int n,int i)
{
int j;
char temp[n];
int depth=0;

   for(j=i;j<n;j++)
   {
      temp[depth]=a[j];
      temp[depth+1]='\0';

      cout<<temp<<endl;

      depth++;

      fun(a,n,j+1);
   }
}

int main()
{
char a[]="abcde";
int n=strlen(a);
fun(a,n,0);
}
