/*
Algorithm: here first we enque positions of all the elements with value=2, each element can reach to top,right,bottom,left from its position, after
enqueing all the elements with value=2 ,we enqueue a node (-1,-1) which marks the end of one time frame,so now we traverse the queue and look for all
reachale positions from every element taken from queue, if we find any element in neighbour with value=1 it means it can be rotten up by the current
element,now it will also be enqueued i.e it will be looked in 2nd time frame(after (-1,-1) ) ans so on for other elements
*/
#include<iostream>
#include<queue>
#define r 3
#define c 5

using namespace std;

struct node
{
    int i,j;
};

int del(struct node temp)
{
    if(temp.i==-1&&temp.j==-1)
        return 1;
    return 0;
}

int check(int i,int j)
{
    if(i>=0&&j>=0&&i<r&&j<c)
        return 1;
    return 0;
}

int checkOverAll(int arr[][c])
{
    int i,j;

    for(i=0;i<r;i++)
   {
    for(j=0;j<c;j++)
    {
        if(arr[i][j]==1)
        return 0;
    }
   }
return 1;
}

int fun(int arr[][c])
{
queue<struct node>q;
int i,j,flag,ans=0;

struct node temp;

for(i=0;i<r;i++)
{ // for 1 starts
    for(j=0;j<c;j++)
    {
        if(arr[i][j]==2)
        {
             temp.i=i;
             temp.j=j;
           q.push(temp);
        }
    }
} //for 1 ends

temp.i=-1;
temp.j=-1;
q.push(temp);

while(!q.empty())
{

flag=0;

  while(!del(q.front()))
 {
     temp=q.front();

   //bottom
   if(check(temp.i+1,temp.j) && arr[temp.i+1][temp.j]==1 )
   {
       if(!flag)
       flag=1;

       arr[temp.i+1][temp.j]=2;
       temp.i++;
       q.push(temp);
       temp.i--;
   }

   //top
   if(check(temp.i-1,temp.j) && arr[temp.i-1][temp.j]==1 )
   {
       if(!flag)
       flag=1;

       arr[temp.i-1][temp.j]=2;
       temp.i--;
       q.push(temp);
       temp.i++;
   }

   //right
   if(check(temp.i,temp.j+1) && arr[temp.i][temp.j+1]==1 )
   {
       if(!flag)
       flag=1;

       arr[temp.i][temp.j+1]=2;
       temp.j++;
       q.push(temp);
       temp.j--;
   }

   //left
   if(check(temp.i,temp.j-1) && arr[temp.i][temp.j-1]==1 )
   {
       if(!flag)
       flag=1;

       arr[temp.i][temp.j-1]=2;
       temp.j--;
       q.push(temp);
       temp.j++;
   }
    q.pop();

 }//inner while ends
 q.pop();

 if(flag==1)
    ans++;

    if(!q.empty())
    {
        temp.i=-1;
        temp.j=-1;
        q.push(temp);
    }
}// main while ends

return checkOverAll(arr)?ans:-1;
}// fun ends

int main()
{
 int arr[][c] = { {2, 1, 0, 2, 1},
                  {1, 0, 1, 2, 1},
                  {1, 0, 0, 2, 1}
                };

int ans=fun(arr);

if(ans==-1)
    cout<<"cannot rot all oranges";
else
    cout<<"time:"<<ans;
}
