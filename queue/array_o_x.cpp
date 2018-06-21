#include<iostream>

using namespace std;

int fun(char arr[],int n)
{
int i,p,time=0,j;
int count_zero=0;

for(i=0;i<n;i++)
    if(arr[i]=='o')
    count_zero++;

while(count_zero>0) {
p=0;
for(i=0;i<n;i++)
{
    if(arr[i]=='x')
    {
        if(i-1>=0&&(arr[i-1]=='o')){
          p=1;
            count_zero--;
            arr[i-1]='x';
        }

        if(i+1<n&&(arr[i+1]=='o')){
            p=1;
            count_zero--;
            arr[i+1]='x';
        }
    }cout<<"i-"<<i<<": ";
    for(j=0;j<n;j++)
    cout<<arr[i]<<" ";
   cout<<endl;

 }

 if(p==1)
        time++;

}// while ends
return time;
}

int main()
{
    char arr[]={'o','x','o','o','o','x','o','o','o'};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"time: "<<fun(arr,n);
}
