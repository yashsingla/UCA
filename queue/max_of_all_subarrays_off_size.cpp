/*
Time Complexity: O(n). It seems more than O(n) at first look. If we take a closer look, we can observe that
every element of array is added and removed at most once. So there are total 2n operations.

Auxiliary Space: O(k)
*/

#include<iostream>
#include<deque>

using namespace std;

void printMax(int a[],int n,int k)
{
    deque<int>s;
    int i;
    for(i=0;i<k;i++)
    {
        if(!s.empty()&&a[i]>=a[s.back()])
            s.pop_back();

        s.push_back(i);
    }
    for(;i<n;i++)
    {
        cout<<a[s.front()]<<" ";

        if(!s.empty()&&s.front()<=i-k)
            s.pop_front();

          if(!s.empty()&&a[i]>=a[s.back()])
            s.pop_back();

            s.push_back(i);
}
cout<<a[s.front()]<<" ";

}//function ends


int main()
{
    int a[]={12,1,78,90,57,89,56};
    int n=sizeof(a)/sizeof(a[0]);
    int k=3;

    printMax(a,n,k);
}
