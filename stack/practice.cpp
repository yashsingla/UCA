//header file for sort() function is algorithm
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int comp(int a,int b)
{
    return a>b;
}

int main()
{
    int a[]={4,1,3,2,6,7,8,5};
    int n=sizeof(a)/sizeof(a[0]);
    //sort(a,a+n,comp); //to sort array in particular order we use comparator comp,other sort(a,a+n) sorts the array in asec order
                      //by default
     sort(a,a+2);
     int i;
    for(i=0;i<n;i++)
       printf("%d ",a[i]);
}
