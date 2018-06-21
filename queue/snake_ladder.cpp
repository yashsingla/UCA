#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node
{
    int v;
    int dist;
};

int snakes_ladder(int moves[],int n)
{
vector<int>visited(n,0);

queue<struct node>q;

struct node s={0,0};
visited[0]=1;
q.push(s);
struct node temp;
while(!q.empty())
{
    temp=q.front();

    int v=temp.v;

    if(v==n-1)
        break;

    int i;
q.pop();

    for(i=v+1;i<=v+6&&i<n;i++)
    {
        if(!visited[i])
        {
            struct node a;
            a.dist=temp.dist+1;
            visited[i]=1;

            if(moves[i]!=-1)
                a.v=moves[i];
            else
                a.v=i;
            q.push(a);

        } // if ends

    }//for ends

}// while ends
return temp.dist;
}// function ends

int main()
{
int n=30;

int moves[30]={-1};

//ladder
moves[2]=21;
moves[4]=7;
moves[10]=25;
moves[19]=28;

//snake
moves[26]=0;
moves[20]=8;
moves[16]=3;
moves[18]=6;

cout<<"minimum moves: "<<snakes_ladder(moves,n);
}
