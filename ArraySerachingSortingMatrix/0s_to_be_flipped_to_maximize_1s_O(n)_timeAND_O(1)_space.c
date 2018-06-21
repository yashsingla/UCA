#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int fun(int a[],const int n,int m)
{
    int wR=0,wL=0;
    int zeroCount=0;
    int bestL=0,bestWindow=0;
    int i;

    for(i=0;i<n;i++)
    {
        if(zeroCount<=m)
        {
            if(a[wR]==0)
                zeroCount++;
            wR++;
        }

        if(zeroCount>m)
        {
            if(a[wL]==0)
                zeroCount--;
            wL++;
        }

        if(wR-wL>bestWindow)
        {
            bestWindow=wR-wL;
            bestL=wL;
        }
    }
    for(i=0;i<bestWindow;i++)
    {
        if(a[bestL+i]==0)
            printf("%d ",bestL+i);
    }
}

int main()
{
    int a[]={1,0,0,1,1,0,1,0,1,1,1};
    //int a[]={0,1,1,1,0,0};
    int m=2;
    int n=sizeof(a)/sizeof(a[0]);
    fun(a,n,m);
}
/*
there is one more solution in which O(n) time and O(n) space

let left[] and right be two arrays to store consecutive number of 1's in left of 0 and right of 0 at any position in array

arr[]={1,0,0,1,1,0,1,0,1,1,1}
      {0,1,2,3,4,5,6,7,8,9,10} //indexes of arr

   left[1]=1,right[1]=0 ,total=1+1=2(left of index-0 has 1 consecutive one and in right it has zero)
   left[2]=0,right[2]=2  total=0+2+1=3(extra added one is for '0' at index specified)
   left[5]=2,right[5]=1  total=2+1+1=4
   left[7]=1,right[7]=3  total=1+3+1=5

   let m=2
   now we can combine indexes only in increasing order..like for m=2 (1,2) || (2,5) || (5,7)
   we need to find maximum sum of total of all the combination

   ans for above= total[5]+total[7]+(7-5-1)=8
                                     bigger index value-smaller index value -1;
*/
