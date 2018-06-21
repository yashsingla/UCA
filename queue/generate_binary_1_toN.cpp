#include<iostream>
#include<queue>

using namespace std;

void print(int n)
{
    queue<string>q;

    q.push("1");

    while(n--)
    {
        string s=q.front();
        q.pop();
        cout<<s<<endl;

       string s1=s;
        q.push(s.append("0"));
        q.push(s1.append("1"));

    }
}

int main()
{
    int n;
    cout<<"n:";
    cin>>n;
    print(n);
}
