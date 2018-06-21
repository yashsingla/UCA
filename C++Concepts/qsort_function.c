#include<stdio.h>
#include<stdlib.h>

int cmp(const void *p,const void *q)
{
    int l= *(int*)p;
    int m= *(int*)q;
    return l-m;
}

int main()
{
    int a[]={4,1,3,2,6,7,8,5};
    int n=sizeof(a)/sizeof(a[0]);

    qsort(a,n,sizeof(a[0]),cmp);
    int i;
    for(i=0;i<n;i++)
       printf("%d ",a[i]);
       // cout<<a[i]<<" ";
}
