#include<iostream>

using namespace std;

void multiply(int arr[2][2],int temp[2][2])
{
    int w= arr[0][0]*temp[0][0] + arr[0][1]*temp[1][0] ;
    int x= arr[0][0]*temp[0][1] + arr[0][1]*temp[1][1] ;
    int y= arr[1][0]*temp[0][0] + arr[1][1]*temp[1][0] ;
    int z= arr[1][0]*temp[0][1] + arr[1][1]*temp[1][1] ;

    arr[0][0]=w;
    arr[0][1]=x;
    arr[1][0]=y;
    arr[1][1]=z;
}

void power(int arr[2][2],int n)
{
    int temp[2][2]={{1,1},{1,0}};
     if(n<=1)
     return;

    power(arr,n/2);
    multiply(arr,arr);

    if(n%2!=0)
    multiply(arr,temp);
}

int find_nth_util(int n)
{
    int arr[2][2]={{1,1},{1,0}};

     power(arr,n);

    return arr[0][0];
}


int main()
{
int n=5;
cout<<"no. of steps:"<<find_nth_util(n);
}
