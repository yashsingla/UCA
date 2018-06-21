#include<iostream>
#include<stack>
using namespace std;

int fun(char a[])
{
    int i=0,len=0;
    stack<int>s;
    while(a[i]!='\0')
    {
        if(a[i]=='(')
            s.push(i);
        else
        {
            if(!s.empty())
            {
             if(a[s.top()]=='('){
                 len=len+2;
                s.pop();
                }
            }
        }
        i++;
    }
    //cout<<"len:"<<len;
    return len;
}

int main()
{
char s[]=")()()((()))"; //expected:10
//char s[]="(((((()";
cout<<"length of longest valid substring:"<<fun(s);
}
