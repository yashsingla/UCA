#include<iostream>
#include<limits.h>

using namespace std;

int coin_change_recursive(int coins[],int v,int n)
{
    if(v==0)
        return 0;

     int res=INT_MAX;
     int i;

     for(i=0;i<n;i++)
     {
         if(coins[i]<=v)
         {
             int x=coin_change_recursive(coins,v-coins[i],n);

             if(x!=INT_MAX&&x+1<res)
                res=x+1;
         }
     }
     return res;
}

int coin_change_dynamic(int coins[],int v,int n)
{
    int table[v+1];
    int i,j;

table[0]=0;
   for(i=1;i<=v;i++)
    table[i]=INT_MAX;

     for(i=1;i<=v;i++)
     {
         for(j=0;j<n;j++)
         {
             if(coins[j]<=i)
             {
                 int sub_res=table[i-coins[j] ];

                 if(sub_res!=INT_MAX&&sub_res+1<table[i])
                    table[i]=sub_res+1;
             }
         }

     }
     return table[v];
}


int main()
{
    int coins[] = {9,6,5,1};
    int  v = 11;
    int n = sizeof(coins)/sizeof(coins[0]);

    //cout<<"coin change: "<<coin_change_recursive(coins,v,n);

    cout<<"coin change: "<<coin_change_dynamic(coins,v,n);
}
