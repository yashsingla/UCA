#include<iostream>
#include<string.h>

using namespace std;

void fun(char a[],int n,int i,int *c)
{
     if(i<0||i>=n)
        return;

    int p=0;

      if(a[i]==a[i+1])
     { cout<<"cut ";
         int k=1,j;

        (*c)=(*c)+2;

       for(j=i;j<n-1;j++)
          a[j]=a[j+2];

         p=1;
     }

     if(p==1)
     {
         if(a[i]==a[i-1]){
          cout<<"i:"<<i<<endl;
          fun(a,n,i-1,c);
         }
         else
         if(a[i]==a[i+1]){
          cout<<"i:"<<i<<endl;
           fun(a,n,i,c);
         }
         else{
            cout<<"i:"<<i<<endl;
      fun(a,n,i+1,c);
         }
     } //p if ends

     else{
          cout<<"i:"<<i<<endl;
      fun(a,n,i+1,c);
     }
}

int main()
{
    //char a[]="abccbcba";
    char a[]="abbcckm";
    int n=strlen(a);
      int c=0;
    fun(a,n,0,&c);
    cout<<"c:"<<c;
    cout<<a;
}
