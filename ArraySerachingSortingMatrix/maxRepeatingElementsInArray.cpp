/*Given an array of size n, the array contains numbers in range from 0 to k-1 where k is a positive integer and k <= n.
 Find the maximum repeating number in this array. For example, let k be 10 the given array be arr[] = {1, 2, 2, 2, 0, 2, 0, 2, 3, 8, 0, 9, 2, 3},
 the maximum repeating number would be 2. Expected time complexity is O(n) and extra space allowed is O(1). Modifications to array are allowed.
 IMP: ask interviewer if modification can be done in the array*/

//Expected time complexity is O(n) and extra space allowed is O(1), 1)navie: o(n^2) and O(1) time using two loops ,2) O(n) time and spacw

 #include<iostream>
 #include<climits>

 using namespace std;

int fun(int a[],int k,int n)
{
  int i,maximum=INT_MIN, index;

  for(i=0;i<n;i++)
  {
      a[a[i]%k]=a[a[i]%k]+k;
  }

  for(i=0;i<n;i++)
  {
    if(a[i]>maximum){
        maximum=a[i];
        index=i;
    }
  }
return index;
}

 int main()
 {
     int a[]={2, 3, 3, 5, 3, 4, 1, 7}, k = 8, n = 8;

     cout<<"max repeating element is:"<<fun(a,k,n);
 }
/*
How does it works?

>>since for every i ,we are incrementing element at "a[i]%k"-->index of element to be incremented by k
>>now like for value a[i]=3 above, whenever a[i]=3 comes , we will increment element at index=3%8=3 i.e. a[3]=5 is incremented everytime
>>Note that k is added maximum number of times at the index equal to maximum repeating element and all array elements are smaller than k.

*/
