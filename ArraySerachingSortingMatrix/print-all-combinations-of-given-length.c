#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void generate_combo(int a[],int n,int k,int size,int m,char out[])
{
    if(size==k)
    {   out[k]='/0';
        printf("%s",out);
        printf("\n");
        return;
    }

    int j;

   for(j=0;j<n;j++)
   {
       //strcat(out[m],a[j]);
       out[m]='a'+a[j];

    generate_combo(a,n,k,size+1,m+1,out);
   }

}


void generate(int a[],int n,int k)
{  int size=0,i=0,m=0;
char out[10]="";
    generate_combo(a,n,k,size,m,out);
}

int main()
{
char a[]={'a','b','c'};
int k=3;

int n=sizeof(a)/sizeof(a[0]);

generate(a,n,k);

}
