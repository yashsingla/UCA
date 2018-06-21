#include<iostream>
#include<string>
//#include<cstring>

using namespace std;

bool diction(string k)
{
     string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};

    int n=sizeof(dictionary)/sizeof(dictionary[0]);

    int i;
    for(i=1;i<=n;i++)
    if(dictionary[i].compare(k)==0)
        return true;

return false;
}

bool word_break(string s)
{

      int n=s.size();

      if(n==0)
    return true;

      int i;
  for(i=1;i<=n;i++)
  {
         if(diction(s.substr(0,i))&&word_break(s.substr(i,n-i)))
            return true;
  }
return false;
}

int main()
{
   if(word_break("ilike"))
    cout<<"yes"<<endl;
    else
   cout<<"No"<<endl;

   if(word_break("samsung"))
    cout<<"yes"<<endl;
    else
   cout<<"No"<<endl;
}
