/*ALGORITHM: kth smallest element
1) BUILD A MAX_HEAP FOR FIRST K ELEMENTS OF ARRAY...O(K) (arr[0] to arr[k-1]) of the given array)
2)  For each element, after the k’th element (arr[k] to arr[n-1]), compare it with root of MH.
 a) If the element is less than the root then make it root and call heapify for MH
 b) Else ignore it.
// The step 2 is O((n-k)*logk)

3) Finally, root of the MH is the kth smallest element.

Time complexity of this solution is O(k + (n-k)*Logk)
*/
#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=(*a);
    (*a)=(*b);
    (*b)=temp;
}



void min_heapify(int a[],int i,int n)
{
    int l=2*i+1;
    int r=2*i+2;
    int smallest;

    if(l<n&&a[l]<a[i])
        smallest=l;

        else
        smallest=i;

    if(r<n&&a[r]<a[smallest])
         smallest=r;

     if(smallest!=i)
     {
         swap(&a[i],&a[smallest]);
         min_heapify(a,smallest,n);
     }

}

void min_heap(int a[],int n)
{
    int i;
    for(i=(n-2)/2;i>=0;i--)
        min_heapify(a,i,n);
}


//to find kth largest element
int fun
(int a[],int k,int n)
{
   int temp[k],i;

   for(i=0;i<k;i++)
   {
       temp[i]=a[i];
   }
      min_heap(temp,k);

    while(i<n)
    {
        if(a[i]>temp[0])
        {
            temp[0]=a[i];
            min_heapify(temp,0,k);
        }//inner if ends
      i++;
  }//while ends

 return temp[0];

}//function ends

int main()
{
    int a[]={7,10,3,4,20,15};
    int n=sizeof(a)/sizeof(a[0]);
    int k=6;

  int x=fun(a,k,n);
  printf("kth largest element is :%d",x);

}
