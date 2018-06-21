#include<iostream>
#include<limits.h>
#include<string>
#include<queue>
#include<vector>
using namespace std;

class node
{
    int x;
    int y;
public:
    node(int a,int b)
    {
        x=a;
        y=b;
    }
    int get_x(){return x;}
    int get_y(){return y;}
};

/*class comparator
{
public:
    int operator()(node &p1,node &p2)
    {
        return p1.get_x()>p2.get_x();
    }
};*/

bool node::operator()(node &p1)
    {
        return get_x()>p1.get_x();
    }

int main()
{
priority_queue<node, vector<node> >q;

q.push(node(1,2));
q.push(node(0,4));
q.push(node(2,5));
q.push(node(7,9));
 while(!q.empty())
  {struct node a=q.top();
    cout<<a.x<<" ";
    q.pop();
  }
}
