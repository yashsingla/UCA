// time complexity: O(NlogN)
#include<stdio.h>
#include<stdlib.h>

int merge(int a[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int i,k,j,left[n1],right[n2],count;

    for(i=0;i<n1;i++)
      left[i]=a[i+l];

   for(i=0;i<n2;i++)
    right[i]=a[m+i-1];

    k=l,i=0,j=0,count=0;

   while(i<n1&&j<n2)
   {
       if(left[i]<=right[j])
       {
           a[k]=left[i];
           i++;
       }
       else
       {
           a[k]=right[j];
           j++;
           count=+(m+1)-i;
       }
       k++;
   }

   while(i<n1)
    a[k++]=left[i++];

   while(j<n2)
    a[k++]=right[j++];

return count;
}

int merge_sort(int a[],int l,int r)
{
    if(l>r)
    return ;

    int m=(l+r)/2;
    int count=0;

   count=merge_sort(a,l,m);
    count+=merge_sort(a,m+1,r);
   count+=merge(a,l,m,r);

    return count;
}

int count_inversion(int a[],int n)
{
    return merge_sort(a,0,n-1);
}

int main()
{
    int a[]={1,20,6,4,5};
    int n=sizeof(a)/sizeof(a[0]);

    int count=count_inversion(a,n);

    printf("inversion count:%d",count);
}
