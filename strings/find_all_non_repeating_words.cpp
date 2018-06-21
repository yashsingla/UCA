#include<iostream>
#include<map>
#include<string>

using namespace std;

void fun(string a[],int a1,string b[],int b1)
{
    map<string,int>m;

    int i;
    for(i=0;i<a1;i++)
    if(m.find(a[i])==m.end())
    m[a[i]]++;

for(i=0;i<b1;i++)
    if(m.find(b[i])==m.end())
        m[b[i]]++;
    else
        m.erase(b[i]);

map<string,int>::iterator it=m.begin();

while(it!=m.end())
{
    cout<<(*it).first<<" ";
    it++;
}
}

int main()
{
    string a[]={"i","have","a","blue","pen"};
    int a1=sizeof(a)/sizeof(a[0]);

     string b[]={"i","got","a","red","pen"};
     int b1=sizeof(b)/sizeof(b[0]);

     fun(a,a1,b,b1);
}
