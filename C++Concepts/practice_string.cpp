#include<iostream>
#include<string>
#include<limits.h>
#include<utility>
#include<vector>
#include<tr1/unordered_map>

using namespace std::tr1;
using namespace std;

namespace std {
    namespace tr1 {
        template<>
         hash< std::pair<int,int> > {
            std::size_t operator()( tr1 & c ) const
            {
                return c.m_val;
            }
        }
    }
}

int fun(vector<int>from,vector<int>to,vector<int>weight,int f1,int t1,int w1)
{
    unordered_map< pair<int,int> ,int >m;

    int i,j;

    for(i=0;i<f1;i++)
    {
        pair<int,int>p(from[i],to[i]);
        m[p]++;
    }

    for(i=0;i<f1;i++)
    {
        for(j=0;j<t1;j++)
        {
            if(from[i]==to[j]&&weight[i]==weight[j]){
         pair<int,int>p(from[j],to[i]);
           m[p]++;
            }
       }
   }
   int cnt=0;
   int maxi=INT_MIN;

       for(i=0;i<f1;i++)
       {   pair<int,int>p(from[j],to[i]);
           int prod=(p.first)*(p.second);
           if(m[p]>cnt)
           {
               cnt=m[p];
               maxi=prod;

           }
           else
          if(m[p]==cnt)
           {
               if(prod>maxi)
                  maxi=prod;
           }

        }
        return maxi;
}

int main()
{
vector<int>from{1,1,2,2,2};
vector <int>to{2,2,3,4,3};
vector<int>weight{1,2,1,3,4};


int f1=from.size();
int t1=to.size();
int w1=weight.size();

int x=fun(from,to,weight,f1,t1,w1);
cout<<"x:"<<x;
}
