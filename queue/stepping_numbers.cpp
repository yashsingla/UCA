// A number is called stepping number if all adjacent digits have an absolute difference of 1. 321 is a Stepping
//Number while 421 is not.

#include<iostream>
#include<queue>

using namespace std;

//bfs solution
void bfs(int n,int m,int i)
{
queue<int>q;
q.push(i);

while(!q.empty())
{
    int k=q.front();
    q.pop();

    if(k<=m&&k>=n)
        cout<<k<<" ";

    if(k==0||k>m)
        continue;

    int last=k%10;

    int stepA=k*10+(last-1);
    int stepB=k*10+(last+1);

    if(last==0)
        q.push(stepB);
    else
    if(last==9)
    q.push(stepA);
    else
    {
        q.push(stepA);
        q.push(stepB);
    }
  }
}

//dfs solution
void dfs(int n,int m,int i)
{
      int k=i;

    if(k<=m&&k>=n)
        cout<<k<<" ";

    if(k==0||k>m)
        return;

    int last=k%10;

    int stepA=k*10+(last-1);
    int stepB=k*10+(last+1);

    if(last==0)
      dfs(n,m,stepB);
    else
    if(last==9)
    dfs(n,m,stepA);
    else
    {
        dfs(n,m,stepA);
        dfs(n,m,stepB);
    }
}

void stepping_numbers(int n,int m)
{
    int i;
    for(i=0;i<=9;i++)
        dfs(n,m,i);
        //bfs(n,m,i);
}

int main()
{
    int n=22,m=35;

    stepping_numbers(n,m);
}
