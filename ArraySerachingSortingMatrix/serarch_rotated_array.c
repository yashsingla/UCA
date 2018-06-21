#include<stdio.h>

int search_rotated(int a[],int l,int r,int x)
{
    if(l>r)
    return 0;

    int m=(l+r)/2;

        if(a[m]==x)
        return m;

    if(a[l]<=a[m])
    {
      if(x>=a[l]&&x<=a[m])

        return search_rotated(a,l,m-1,x);
      return search_rotated(a,m+1,r,x);
    }


   if(x>=a[m]&&x<=a[r])
        return search_rotated(a,m+1,r,x);
      return search_rotated(a,l,m-1,x);
}

int main()
{
    int a[]={3,4,5,1,2};
    int n=sizeof(a)/sizeof(a[0]);
   int  x=1;

    int k=search_rotated(a,0,n-1,x);
    if(k>0)
    printf("element found at index:%d",k);
    else
    printf("element not found");
}
