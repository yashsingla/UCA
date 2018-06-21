#include<stdio.h>
#include<stdlib.h>

void closest_sum(int a[],int n,int x)
{
   int l=0,r=n-1,diff=1000,n1,n2;

   while(r>l)
   {
       if(abs(a[l]+a[r]-x)<diff)
       {
           n1=l;
            n2=r;
           diff=abs(a[l]+a[r]-x);
       }

       if(a[l]+a[r]>x)
        r--;
       else
        l++;

   }
printf("n1:%d\nn2:%d",a[n1],a[n2]);
}

int main()
{
   int a[]={10, 22, 28, 29, 30, 40};
   int x=54;

   int n=sizeof(a)/sizeof(a[0]);

   closest_sum(a,n,x);

}
