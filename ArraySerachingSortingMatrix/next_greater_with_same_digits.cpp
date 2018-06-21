#include<iostream>
#include<cstring>
#include<algorithm>
#include<limits.h>
using namespace std;

void swapp(char *a, char *b)
{
    char temp=(*a);
    (*a)=(*b);
    (*b)=temp;
}

char *fun(char *a,int n)
{
    int i,j;

    for(i=n-1;i>0;i--)
    {
        if(a[i-1]<a[i])
        {
            j=i-1;
            break;
        }
   }
   if(i==0)
   {
       cout<<"No such number exits";
       return 0 ;
   }

   int mini=INT_MAX,index;

     for(i=j+1;i<n;i++)
       if(a[i]<mini&&a[i]>a[j]){
         mini=a[i];
         index=i;
       }

     swapp(&a[j],&a[index]);

   sort(a+j+1,a+n-1);
cout<<"new:"<<a;
}

int main()
{
    //char str[]="1234";
    char str[]="534976";
    int n=sizeof(str)/sizeof(str[0]);
cout<<"old:"<<str<<endl;
   fun(str,n);
}
