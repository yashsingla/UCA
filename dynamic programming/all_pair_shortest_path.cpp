// time complexity: O(v^3)
// {i}---p1---(k)---p2---{j} , path from node-i to node-j can be achieved via travelling from intermediate node k..(k vaires from 1 to v)..
#include<iostream>
#include<limits.h>
#define inf INT_MAX
#define v 4

using namespace std;

void fun(int g[v][v])
{
    int dist[v][v];
    int i,j,k;

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            dist[i][j]=g[i][j];
        }
    }

/* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */

    for(k=0;k<v;k++){ // this loop signifies the intermediate nodes via which distance of path from i to j will be calculated i.e for k=0 only v1 can used
    for(i=0;i<v;i++)  // as intermediate..for k=1 (v1,v2) can be used to calculate the shortest path...hence at k=v-1, we will get the final 2d matrix
                     // containing shortest-distance of all pair of vertices.
    {
        for(j=0;j<v;j++)
        {
            if(dist[i][k]!=inf && dist[k][j]!=inf && ( dist[i][k]+dist[k][j] < dist[i][j] ))

                dist[i][j]=dist[i][k]+dist[k][j] ;

        }// for j ends
    }  // for i ends
  } // for k ends

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
           cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main()
{

int g[v][v] = { {0, 5, inf, 10},
                {inf, 0,   3, inf},
                {inf, inf, 0,   1},
                {inf, inf, inf, 0}
              };

     fun(g);
}
