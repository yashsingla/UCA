#include<iostream>
#include<stack>
#include<limits.h>

using namespace std;

int hist(int a[],int n)
{
    stack<int>s;
    int area_top;
    int max_area=INT_MIN;

    int i=0;

    while(i<n)
    {
        if(s.empty()||a[i]>a[s.top()])
            s.push(i++);
        else
        {
            int tp=s.top();
            s.pop();

            area_top=a[tp]*(s.empty() ?i:i-s.top()-1);

            if(area_top>max_area)
              max_area=area_top;
}}

    while(!s.empty())
    {
        int tp=s.top();
            s.pop();

            area_top=a[tp]*(s.empty()?i:i-s.top()-1);

            if(area_top>max_area)
              max_area=area_top;
    }
    return max_area;
}

int main()
{
    int a[]={6,2,5,4,5,1,6};
int n=sizeof(a)/sizeof(a[0]);

int x=hist(a,n);
cout<<"largest area:"<<x;
}
