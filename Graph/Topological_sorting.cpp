#include<iostream>
#include<list>
#include<vector>
using namespace std;

void add(int i,int j,list<int>adj[])
{
adj[i].push_back(j);
}

void print(list<int>adj[],int v)
{
    int i;
  list<int>::iterator itr;
  for(i=0;i<v;i++)
  {  cout<<i<<" :";
      for(itr=adj[i].begin();itr!=adj[i].end();itr++)
      {
           cout<<(*itr)<<" ";
      }
      cout<<endl;
  }

}

int main()
{
   int v=5;
   list<int>*adj=new list<int>[5];
   //=new vector<int>[v];
   //adj=new vector<int>(v);

   add(5,3,adj);
   add(5,0,adj);
   add(3,2,adj);
   add(2,1,adj);
   add(4,1,adj);
   add(4,0,adj);

//   print(adj,v);

    int i;
  list<int>::iterator itr;
  for(i=0;i<v;i++)
  {  cout<<i<<" :";
      for(itr=adj[i].begin();itr!=adj[i].end();itr++)
      {
           cout<<(*itr)<<" ";
      }
      cout<<endl;
  }
}
