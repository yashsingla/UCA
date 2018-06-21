/*here idea is to create a empty stack and keep on adding elements from array to stack till we find an element that is
greater than the stack top...after finding greater element than stack top ,keep on removing stack top element smaller than the
current element from the array till stack becomes empty and make last removed element as root,if we find element from array lesser
than the root..return false..i.e doesnt represents preorder*/

#include<bits/stdc++.h>
using namespace std;

bool check_preorder(int pre[],int n)
{
     stack<int>s;
int root=INT_MIN,i;
    for(i=0;i<n;i++)
    {
        if(pre[i]<root)
            return false;

        while(!s.empty()&&s.top()<pre[i])
        {
            root=s.top();
            s.pop();
        }
     s.push(pre[i]);

    }

return true;
}
/*my solution, same as above but only order of statements are different
int check_preorder(int arr[],int n)
{
     stack<int>s;
int root=INT_MIN,i;
    for(i=0;i<n;i++)
    {
        if(s.empty()||s.top()>=arr[i])
            s.push(arr[i]);
        else
        if(s.top()<arr[i]){
        while(!s.empty()&&s.top()<arr[i])
        {
            root=s.top();
            s.pop();
        }
        }
     s.push(arr[i]);

     if(root>s.top())
        return 0;
    }
return 1;
}

*/

int main()
{
    int pre1[]={40, 30, 35, 80, 100};
    int n=sizeof(pre1)/sizeof(pre1[0]);

    if(check_preorder(pre1,n))
        cout<<"It is preorder";
    else
        cout<<"Not preorder";
}
