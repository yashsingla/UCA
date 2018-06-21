#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int min(int a,int b)
{
    return a<b?a:b;
}

int max(int a,int b)
{
    return a>=b?a:b;
}

//O(n^2) solution
int fun(int a[],int n)
{
    int i;
   // int max_left=a[0],max_right=a[n-1];
    int current=0;

    for(i=0;i<n;i++)
    {
        int max_left=a[i-1],max_right=a[i+1];
        int j=i-1,k=i+1;


        while(j>=0)
        {
            if(a[j]>max_left)
                max_left=a[j];
            j--;
        }

        while(k<n)
        {
            if(a[k]>max_right)
            max_right=a[k];

            k++;
        }
        printf("max_left:%d\n",max_left);
        printf("max_right:%d\n",max_right);

      current+=max(min(max_left,max_right)-a[i],0);
      printf("current:%d\n\n",current);
    }
    return current;
}

//O(n) solution
int fun1(int a[],int n)
{
    int left[n],right[n];
    int i;

    left[0]=a[0];
    for(i=1;i<n;i++)
    left[i]=max(left[i-1],a[i]);

    right[n-1]=a[n-1];
    for(i=n-2;i>=0;i--)
    right[i]=max(right[i+1],a[i]);

int current=0;
    for(i=0;i<n;i++)
        current+=min(left[i],right[i])-a[i];

    return current;
}

int main()
{
    int a[]={3,0,0,2,0,4};
    //int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int n=sizeof(a)/sizeof(a[0]);

  //  int x=fun(a,n);  O(n^2) solution
    int x=fun1(a,n); //O(n) solution
    printf("x:%d\n",x);
}
