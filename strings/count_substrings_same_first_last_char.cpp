#include<iostream>
#include<string>
using namespace std;

int countSubstringWithEqualEnds(string str ,int i ,int j ,int n)
{
     if(n == 1)
        return 1;

     if(n == 2)
        return 2;

    if(str[i] == str[j])
        return  1 + countSubstringWithEqualEnds(str,i+1,j,n-1) + countSubstringWithEqualEnds(str,i,j-1,n-1) - countSubstringWithEqualEnds(str,i+1,j-1,n-2);
    else
        return  countSubstringWithEqualEnds(str,i+1,j,n-1) + countSubstringWithEqualEnds(str,i,j-1,n-1) - countSubstringWithEqualEnds(str,i+1,j-1,n-2);
}

int main()
{
    string str = "abcab";
    int n = str.length();
    cout << countSubstringWithEqualEnds(str,0,n-1,n);
}
