#include<iostream>
#include<string>
using namespace std;

int check_rotation(string s1,int n1,string s2,int n2)
{
  // to check for  anti-clockwise
    string temp=s1;
   temp.append(temp,0,2);
   temp.erase(temp.begin(),temp.begin()+2);
   if(temp.compare(s2)==0)
    return 1;

// to check for  clockwise
    temp=s1.substr(n1-2,2);
   s1.erase(s1.end()-2,s1.end());
   temp.append(s1);
 //cout<<"temp: "<<temp<<endl;

  if(temp.compare(s2)==0)
    return 1;

return 0;
}

int main()
{
    string s1="amazon";
    int n1=s1.length();
    string s2="onamaz";
    int n2=s2.length();

   if(check_rotation(s1,n1,s2,n2))
    cout<<"yes";
   else
    cout<<"no";
}

