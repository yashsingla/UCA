#include<iostream>
#include<queue>
#include<list>
using namespace std;

class myComparator{

public:
    int operator()(int x,int y)
{
    return x>=y?1:0;
}

};

int main()
{
    priority_queue<int, vector<int> ,myComparator >pq(2,1);
//priority_queue<int>pq;

    pq.push(3);
    pq.push(4);
    pq.push(4);
    pq.push(8);

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
