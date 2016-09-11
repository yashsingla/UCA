#include<stdio.h>
int count=0;
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
// statements below in comments can be written alternatively to the corresponding statements being used already..will work perfectly
int partition(int a[],int l,int r)
{
    int pivot=a[r];
    int p=l; //or p=l-1;
    int i;

    for(i=l;i<=r-1;i++)
    {
        if(a[i]<=pivot)
        {  // p++;
            count++;
            swap(&a[i],&a[p]);
       p++;
        }
    }
    /*
    swap(&a[p+1],&a[r]);
    return p+1;
    */count++;
    swap(&a[p],&a[r]);

    return p;
}

void quick_sort(int a[],int l,int r)
{
    if(l<r)
    {
        int p=partition(a,l,r);
        quick_sort(a,l,p-1);
        quick_sort(a,p+1,r);
    }
}

int main()
{
    int a[]={9,7,1,2,6,3,4,5};
    int n=sizeof(a)/sizeof(a[0]),i;

   quick_sort(a,0,n-1);
printf("count:%d\n",count);
    for(i=0;i<n;i++)
   printf("%d\t",a[i]);
}
