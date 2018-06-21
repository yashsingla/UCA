#include<iostream>
#include<math.h>
#include<limits.h>
#include<string.h>
using namespace std;


int atoi(char s1[] ,int n)
{
    int i,val=0,a,b;

    for(i=0;s1[i]!='\0';i++){

    int x=s1[i]-'0';
    cout<<"x: "<<x<<endl;
     val=val*10 + x;
    }
    return val;
}

int main()
{
    char s1[]="1234";
    int n=sizeof(s1)/sizeof(s1[0]);

   cout<<"val: "<<atoi(s1,n);
}

