#include<stdio.h>
#include<stdlib.h>

void print(int arr[] ,int n);
void generate_sorted(int a[],int b[],int c[],int i,int j,int m,int n,int len,int flag)
{
    if(flag)
    {//if starts
        int k;
        if(len)
           print(c,len+1);
        for(k=i;k<m;k++){
        if(!len)  //inner if starts
        {
             c[len]=a[k];

      generate_sorted(a,b,c,k+1,j,m,n,len+1,!flag);

        }//inner if ends

     else
     {//inner else starts

         if(a[k]>c[len]){
            c[len+1]=a[k];
      generate_sorted(a,b,c,k+1,j,m,n,len+1,!flag);}
     }//inner else ends

    }//for end
    }//outer if ends
    else
    {  //outer else starts
         int l;
        for( l=j;j<n;j++){
            if(b[l]>c[len]){
            c[len+1]=b[l+1];
        generate_sorted(a,b,c,i,l+1,m,n,len+1,!flag);}
        }
    }  //outer else ens

}

void generate(int a[],int b[],int m,int n)
{   int c[m+n];
    generate_sorted(a,b,c,0,0,m,n,0,1);
}

void print(int arr[],int n)
{int i;
    for(i=0;i<n;i++)
    printf("%d\t",arr[i]);

   printf("\n");
}

int main()
{
    int a[]={10,15,25};
    int b[]={1,5,20,30};

    int m=sizeof(a)/sizeof(a[0]);
    int n=sizeof(b)/sizeof(b[0]);

    generate(a,b,m,n);
}
