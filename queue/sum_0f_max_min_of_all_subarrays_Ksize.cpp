#include<iostream>
#include<deque>
using namespace std;
void printSum(int a[],int n,int k)
{
    deque<int>mini(k);
    deque<int>maxi(k);

    int i,sum=0;

   for(i=0;i<k;i++)
   {
       if(!maxi.empty()&&a[i]>=a[maxi.back()])
          maxi.pop_back();

        if(!mini.empty()&&a[i]<=a[mini.back()])
          mini.pop_back();

       mini.push_back(i);
       maxi.push_back(i);
   }

   for(;i<n;i++)
   {
       sum+=a[maxi.front()]+a[mini.front()];

      if(!mini.empty()&&mini.front()<=i-k)
          mini.pop_front();

        if(!maxi.empty()&&maxi.front()<=i-k)
          maxi.pop_front();


       if(!maxi.empty()&&a[i]>=a[maxi.back()])
          maxi.pop_back();

        if(!mini.empty()&&a[i]<=a[mini.back()])
          mini.pop_back();

       mini.push_back(i);
       maxi.push_back(i);

   }
sum+=a[maxi.front()]+a[mini.front()];

cout<<"sum:"<<sum;

}


int main()
{
    int a[]={2,5,-1,7,-3,-1,-2};
    int n=sizeof(a)/sizeof(a[0]);
    int k=4;

    printSum(a,n,k);
}

