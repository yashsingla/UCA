
#include<stdio.h>

int kth_smallest(int a[],int l,int r,int k)
{
       if(k>0&&k<=(r-l+1)){
    int pivot=randomPartition(a,l,r);

       if(pivot-l==k-1)
        return a[pivot];

        if(pivot-l>k-1)
        return kth_smallest(a,l,pivot-1,k);

    return kth_smallest(a,pivot+1,r,k-pivot+l-1);

       }

    return 0;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int a[],int l,int r)
{
    int x=a[r],i=l,j;

    for(j=l;j<=r-1;j++)
    {
        if(a[j]<=x){
            swap(&a[i],&a[j]);
            i++;
        }
    }
swap(&a[i],&a[r]);
return i;
}

int randomPartition(int a[],int l,int r)
{
    int p=rand()%(r-l+1);
    swap(&a[l+p],&a[r]);
    return partition(a,l,r);
}


int main()
{
int k=3;
int a[]={12, 3, 5, 7, 4, 19, 26};
int n=sizeof(a)/sizeof(a[0]);

int x=kth_smallest(a,0,n-1,k);
printf("kth smallest element:%d\n",x);

}
