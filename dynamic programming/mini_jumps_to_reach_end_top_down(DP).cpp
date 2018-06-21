#include<iostream>
#include<limits.h>
using namespace std;
int mini(int a,int b)
{
    return a<b?a:b;
}
int mini_steps(int arr[],int n)
{
    if(arr[0]==0||n==0)
    return INT_MAX;

    int jumps[n];
    jumps[0]=0;
    int i,j;

    for(i=1;i<n;i++)
    {  jumps[i]=INT_MAX;
        for(j=0;j<i;j++)
        {
            if(i<=j+arr[j]&&jumps[j]!=INT_MAX)
            {
                jumps[i]=mini(jumps[i],jumps[j]+1);
                break;
            }
        }
        if(jumps[i]==INT_MAX)
            return -1;   // because we cannot jump forward and reach end of array ..see case-2
    }
    return jumps[n-1];
}


int main()
{
    //int arr[]={1,3,6,1,0,9}; // case-1;
    int arr[]={1,0,6,1,0,9};// case-2
    int n=sizeof(arr)/sizeof(arr[0]);
     int x=mini_steps(arr,n);
     if(x!=-1)
    cout<<"mini number of steps to reach end: "<<x;
    else
        cout<<"cannot reach end of array";
}
/* IMP EXPLANATION:
>> above solution is top-down approach ,where we calculate things in respect to beginning i.e (top of array)
explanation for case-2:
main condition is: ( i<=j+a[j] )..this condition gives the reach of jth index from index=j
jump[0]=0;
jump[1]=1; // can be reached from 0th index in 1 jump as i=1<=(j=0+a[j]=1)
jump[2]=INT_MAX // cant be reached from 0th because for i=2, j=0,0+a[j]=1 ,main condtion not satisfied
                                                              j=1,1+a[j]=0, main condtition not satisfied
*/
