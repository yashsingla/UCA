/*TIME COMPLEXITY:O(m);
SPACE COMPLEXITY:O(m);
ALGORITHM:
1) idea is to use stack...put all characters from left to right in stack till you encounter a closing parenthesis
2) once you encounter a closing parenthesis..check if element just before it i.e element on top is opening parenthesis..if so
return true..duplicate found else pop the stack till you find opening bracket for encountered closing  bracket
3)repeat the process
*/

#include<iostream>
#include<stack>
using namespace std;

int fun(char k[])
{
    stack<char>s;
    int i=0;

    while(k[i]!='\0')
    {
        if(k[i]==')')
        {
            while(s.top()!='(')
                    s.pop();

                    s.pop();

               if(!s.empty())
            if(s.top()=='('&&k[i+1]==')')
                return 1;
        }else
        s.push(k[i]);
        i++;
    }
    return 0;
}

int main()
{
    char s[]="((a+b)+((e+d)))";
    if(fun(s))
        cout<<"duplicate present";
    else
        cout<<"duplicate not present";
}
