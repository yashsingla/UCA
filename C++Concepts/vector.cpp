#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int main()
{ int i;
    vector<string>v{"hello"};
    vector<string>v1{"hello","yash"};
cout<<"capacity:"<<v1.capacity()<<endl;
v1.push_back("hello1");
cout<<"capacity:"<<v1.capacity()<<endl;
    /*for(i=0;i<4;i++)
    cin>>v[i];
cout<<endl;
   for(i=0;i<4;i++)
    cout<<v[i];
*/

if(v>v1)
    cout<<1;
else
    if(v<v1)
    cout<<0;
   else
   cout<<"equal";


}
