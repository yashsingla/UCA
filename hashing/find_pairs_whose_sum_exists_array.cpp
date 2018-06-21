#include<iostream>
#include<tr1/unordered_set>
#include<algorithm>
using namespace std;
using namespace std::tr1;
/*//time complexity:O(n^2)
//space complexity:O(n)
void fun(int a[],int n)
{
    unordered_set<int>s;
    int i,j;

    for(i=0;i<n;i++)
        s.insert(a[i]);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
                continue;

            if(s.find(a[i]+a[j])!=s.end())
            {
                cout<<a[i]<<" "<<a[j]<<endl;
            }

        }
    }
}
*/
//time complexity:O(n^2)
//space complexity:O(1)
void fun(int a[],int n)
{
    int i,j,left,right;

sort(a,a+n);

    for(i=n-1;i>=0;i--)
    {
        left=0;
        right=i-1;

           while(left<right){
            if(a[left]+a[right]==a[i])
            {
                cout<<a[left]<<" "<<a[right]<<endl;
                left++;
                right--;
            }
            else
                if(a[left]+a[right]>a[i])
                  right--;
            else
                left++;
           }
     }
}

int main()
{
    int a[]={2,8,7,1,5};
    int n=sizeof(a)/sizeof(a[0]);
    fun(a,n);
}
