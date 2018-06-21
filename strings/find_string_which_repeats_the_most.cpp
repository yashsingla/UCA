#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

//you can use haspmap instead ,it will be much better
void MostRepeat(string a[],int n)
{
    sort(a,a+n);
    int i;
    int c=1,maxi=INT_MIN,index;

    for(i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
            c++;
        else
        {
            if(c>maxi)
            {
                index=i;
                maxi=c;
                c=1;
             }
        }//else ends
    }//main for ends;
cout<<"most repeated:"<<a[index];
}

int main()
{
    string a[]={"yash","abc","abc","singla","def","yash"};
    int n=sizeof(a)/sizeof(a[0]);
    MostRepeat(a,n);
}
