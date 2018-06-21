#include<stdio.h>
#include<stdlib.h>

void print(int out[],int k)
{
    int i;
    for(i=0;i<k;i++)
    printf("%d",out[i]);
    printf("\n");
}

void generate_increasing(int k,int n,int j,int size,int out[],int index)
{
    if(size==k)
    {
        print(out,k);
        return ;
    }
    int i;
  for(i=j;i<=n;i++)
  {
      out[index]=i;
    generate_increasing(k,n,i+1,size+1,out,index+1);
  }
}

void generate(int k,int n)
{
    int out[k];
    generate_increasing(k,n,1,0,out,0);
}

int main()
{
    int k=3,n=7;
   int i;
   for(i=1;i<=3;i++)
   generate(i,n);
}
