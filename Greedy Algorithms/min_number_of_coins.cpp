#include<iostream>
#define n 9

using namespace std;

int arr[]={1,2,5,10,20,50,100,500,1000};

void fun(int v)
{
    int i,j,index,k;

    for(i=0;i<n;i++)
    {
        if(arr[i]<=v)
            index=i;
        else
            break;
    }

   int sum=v;
   j=index;

   while(j>=0&&sum>0)
   {
      if( arr[j]<=sum ){
    k=1;
       while((arr[j]*k)<=sum)
         k++;

       k=k-1;

      cout<<"Notes of "<<arr[j]<<":"<<k<<endl;

      sum = sum-( arr[j]*k );
    }

j--;
}
}

int main()
{
int v=198;
cout<<"v:"<<v<<endl;
fun(v);
}
