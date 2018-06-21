
#include<iostream>
#include<stack>
#include<limits.h>
#include<string>
#include<string.h>

using namespace std;

int maxi(int a,int b)
{
   return a>=b?a:b;
}

int longestValid(char a[],int n)
{
    stack<int>s;
    s.push(-1);
   int result=INT_MIN,i;
    for(i=0;i<n;i++)
    {
          if(a[i]=='(')
            s.push(i);
          else

          if(a[i]==')')
          {
              s.pop();

              if(!s.empty())
              {
                  result=maxi(result,i-s.top());
              }
              else
                s.push(i);
          }
    }
    return result;
}

int main()
{
char s[]=")((()))((()";
int n=sizeof(s)/sizeof(s[0]);
int y=longestValid(s,n);

cout<<"length of longest valid substring:"<<y;

}
