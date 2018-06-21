/*
1) time:O(n) ,space:O(d)
   >>put first d elements in auxilary array
   >>shift main array to left by d times
   >>copy elements in auxilary array to main array in last

2) time:O(n*d) ,space:O(1)
   >>one while loop from i=1 to i=d..outer loop
   >>second while loop from j=1 to n-1 and shift elements to left in array one by one and coppy elements in last simultaneously

3) time:O(n) ,space:O(1)
  find GCD of n and d, and shift elements by d jumps..
*/

#include<stdio.h>
#include<stdlib.h>

int GCD(int a,int b)
{
    if(a==1||b==1)
        return 1;
    else
        if(a==b)
        return b;
    else
    if(a>b)
        return GCD(a-b,b);
    else
    return GCD(a,b-a);
}

void fun(int a[],int n,int k)
{
    int m=GCD(n,k);
    int i,j,temp,d;

    for(i=0;i<m;i++)
    {
        temp=a[i];
       j=i;
     while(1)
     {
         d=(k+j)%n;
        if(d==i)
            break;

       a[j]=a[d];
          j=d;
     }//while ends

    a[j]=temp;
    }//outer for ends
}//fun function ends

int main()
{
    int a[]={1,2,3,4,5,6,7};
    int n=sizeof(a)/sizeof(a[0]);
    int d=2;// rotate by 2

    fun(a,n,d);
    int i;

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}


/*
void rvereseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

 Function to left rotate arr[] of size n by d
void leftRotate(int arr[], int d, int n)
{
    rvereseArray(arr, 0, d-1);
    rvereseArray(arr, d, n-1);
    rvereseArray(arr, 0, n-1);
}

rotate left: d=2,n=7
input:1 2 3 4 5 6 7
output:3 4 6 7 1 2

rotate right: d=2,n=7
input:1 2 3 4 5 6 7
output:6 7 1 2 3 4 5

# for rotating right d elements ,u can rotate left fisrt n-d elements
void rightRotate(int arr[], int d, int n)
{
    rvereseArray(arr, 0, n-d-1);
    rvereseArray(arr, n-d, n-1);
    rvereseArray(arr, 0, n-1);
}
*/
