#include<stdio.h>
#include<stdlib.h>

void print(int out[],int k)
{
    int i;
    for(i=0;i<k;i++)
    printf("%d",out[i]);
    printf("\n");
}
void generate_increasing(int a[],int n,int j,int size,int out[],int index,int r)
{
    if(size==r)
    {
        print(out,r);
        return ;
    }
    int i;
  for(i=j;i<n;i++)
  {
      out[index]=a[i];
    generate_increasing(a,n,i+1,size+1,out,index+1,r);
  }


}

void generate(int a[],int n,int r)
{
    int out[r];
    generate_increasing(a,n,0,0,out,0,r);
}

int main()
{
    int a[]={1,2,3,4,5},r=3;
    int n=sizeof(a)/sizeof(a[0]);
   generate(a,n,r);

}

