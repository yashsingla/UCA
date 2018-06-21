#include <iostream>
#include<string>
#include<limits.h>
using namespace std;

int fun(string str,int k,int n)
{
    int max=INT_MIN;
    string temp;
    int len;
    int i,j;

    for(i=0;i<n-k;i++)
    {  int p[256]={0};

      len=k;
        temp=str[i];
        p[str[i]]++;
        len--;

        for(j=i+1;j<n;j++)
        {
            if(p[str[j]]!=0)
            {
                temp=temp+str[j];
                p[str[j]]++;
            }
            else
            if(len>=1&&p[str[j]]==0)
            {
                temp=temp+str[j];
                 p[str[j]]++;
                len--;
            }
            else
            if(len==0)
            break;
    }//inner for
          int f=temp.size();
        if(len==0)
        if(f>max)
        max=temp.size();


}//outer for
  if(max==INT_MIN)
  return -1;
  else
 return max;
}

int main() {

  int t,k;
  string str;

  cin>>t;

  while(t--)
  {
      cin>>str;
      cin>>k;
      int len=fun(str,k,str.size());
      cout<<len<<endl;
  }
	 return 0;
}
