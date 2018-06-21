// now if this question comes then input will be of type
// a1[]={1,1,1,2,3,3,3,4,4,4};...count of all elements will be same except element that appeared once
// a2[]={1,1,1,1,1,3,2,2,2,2,2,4,4,4,4,4}..count of all elemets is 5 except 3

/*solution:
now we will find sum of all bits at a position and if we modulo the sum with count of element and result is not zero then we
include bit at that position in result

example {1,1,1,1,12,3,3,3,3,3}
count of 1st bit from right =10 ..so 10%5==0 ,bit not included
count of 2nd bit=6, 6%5==1,bit included
count of 3rd bit=0,so not included..so on
*/

#include<stdio.h>
#include<stdlib.h>
#define INT_SIZE 32

int fun(int a[],int n)
{
    int result=0,x,i,j;
     int sum;
    for(i=0;i<INT_SIZE;i++)
    {
        x=1<<i;
  sum=0;
        for(j=0;j<n;j++)
        {
            if(x&a[j])
               sum++;
        }
        if(sum%5!=0)
            result=result|x;
    }

    return result;
}

int main()
{  //here we will modulo with 5
    int a[]={1,1,1,1,1,2,3,3,3,3,3};
    int n=sizeof(a)/sizeof(a[0]);

    printf("element is:%d",fun(a,n));
}
