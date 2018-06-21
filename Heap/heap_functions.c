#include<stdio.h>
#include<stdlib.h>


void swap(int *a,int *b)
{
    int temp=(*a);
    (*a)=(*b);
    (*b)=temp;
}

int parent(int k)
{
    return((k-1)/2);
}

void max_heapify(int a[],int i,int n)
{
    int largest;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n&&a[l]>a[i])
        largest=l;
    else
        largest=i;

    if(r<n&&a[r]>a[largest])
        largest=r;

        if(largest!=i)
        {
            swap(&a[i],&a[largest]);
            max_heapify(a,largest,n);
        }
}

void delete_max(int a[],int n)
{
    int max=a[0];
    a[0]=a[n];
    n=n-1;

   max_heapify(a,0,n);
}

void insert(int a[],int key,int *i)
{
    *i=*i+1;
 int   k=*i-1;
   a[k]=key;

   while(k!=0&&a[parent(k)]<a[k])
   {
       swap(&a[parent(k)],&a[k]);
       k=parent(k);
   }

}


void increase(int a[],int i,int key,int n)
{
    a[i]=key;
    while(i>=0&&a[(i-1)/2]<a[i])
    {
        swap(&a[i],&a[(i-1)/2]);
        i=(i-1)/2;
    }

}

void decrease(int a[],int i,int key,int n)
{
    a[i]=key;
    max_heapify(a,i,n);

}


void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);

        printf("\n\n");
}

int main()
{
    int a[]={16,14,10,8,7,9,1,2,4};
    int n=sizeof(a)/sizeof(a[0]);

    /*printf("Before Deleting_max:\n");
    print(a,n);

    delete_max(a,n-1);

    printf("After Deleting_max:\n");
    print(a,n);

    printf("Before Increasing:\n");
    print(a,n);

    increase(a,3,15,n);

    printf("After Increasing:\n");
    print(a,n);


    printf("Before Decreasing:\n");
    print(a,n);

    decrease(a,0,6,n);

    printf("After Decreasing:\n");
    print(a,n);
*/

    printf("Before Inserting:\n");
    print(a,n);

    insert(a,17,&n);

    printf("After Inserting:\n");
    print(a,n);

}

/*  insert in Max heap...
void insert(int a[],int key,int size,int *i)
{
    if((*i)==size)
    {
        printf("overflow");
        return;
    }

*i=*i+1;
int k=(*i)-1;
a[k]=key;

while(k!=0&&a[parent(k)]<a[k])
{
    swap(&a[parent(k)],&a[k]);
    k=parent(k);
}

}//insert ends

void print(int a[],int i)
{
    int j;
    for(j=0;j<i;j++)
        printf("%d\n",a[j]);
}

int main()
{ int a[10];
int size =10,i=0;

 insert(a,3,size,&i);
 insert(a,1,size,&i);
 insert(a,15,size,&i);
 insert(a,5,size,&i);
 insert(a,4,size,&i);
 insert(a,45,size,&i);

print(a,i);

}

*/
