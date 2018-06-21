#include<iostream>
#include<list>

using namespace std;

int main()
{
    vector<int> *adj;
 int i,k;
    for(i=0;i<5;i++)
    {

            adj[0].push_back(i);

    }

   vector<int>::iterator j;

  for(j=adj[0].begin();j!=adj[0].end();j++)
              cout<<(*j);
              cout<<endl;

}
/*
int main()
{
    list<int> *adj;
   int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            adj[i].push_back(1);
        }
    }

    cout<<"print adj:";
list<int>::iterator k;
    for(i=0;i<5;i++)
    { cout<<endl<<"list-"<<i<<":";
    k=adj[i].begin();

     while(k!=adj[i].end())
     {
         cout<<*k<<" ";
         k++;
     }

        cout<<endl;
    }
}
*/
