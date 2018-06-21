#include<stdio.h>

void merge(int a[],int l,int m,int r)
{  int n1=m-l+1;
    int n2=r-m;

    int i,j,k,left[n1],right[n2];
      for(i=0;i<n1;i++){
            left[i]=a[l+i];
            }
      for(j=0;j<n2;j++)
      {
          right[j]=a[j+m+1];
      }

    i=0,j=0;
     k=l;

    while(i<n1 && j<n2)
    {
        if(left[i]<right[j])
        {
            a[k]=left[i];
            i++;
        }
        else
            {
            a[k]=right[j];
            j++;
        }
        k++;
    }//while end

    while(i<n1)
    {
        a[k]=left[i];
            i++;
        k++;
    }

    while(j<n2)
    {
        a[k]=right[j];
            j++;
        k++;
    }
}//function end

void merge_sort(int a[],int l,int r)
{
    int m;
    if(l<r)
    {
         m=(l+r)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main()
{
    int a[]={9,8,7,6,5,4,3},i;
    int n=sizeof(a)/sizeof(a[0]);

    merge_sort(a,0,n-1);

   for(i=0;i<n;i++)
    printf("%d",a[i]);

}
