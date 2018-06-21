#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int fun(int a[],const int n,int m)
{
    int k=m;
    int max=INT_MIN;
    int max_till_now=0;

    int *temp=(int *)malloc(sizeof(int));
   memset(temp,-1,n);

    int p=0;
    int i;
    for(i=0;i<n;i++)
        {
        if(a[i]==1) //2nd if
            max_till_now++;
       else
        if(a[i]==0&&k!=0) //3rd if
        {  temp[p++]=i;
            max_till_now++;
            k=k-1;
        }

      else
        if(a[i]==0&&k<=0)  //1st if starts
        {
            if(max_till_now>max){
                    memset(temp,-1,n);
                   //temp[n]={-1};
                   p=0;
              max=max_till_now;
            }
                i=i-1;

                while(a[i]!=0&&i>0)
                i--;

                k=m;
                max_till_now=0;

        } //3rd if ends

        if(max_till_now>max){
           max=max_till_now;
        }
}//for ends

  for(i=0;i<p;i++)
    printf("%d ",temp[i]);

 return max;
}

int main()
{
    //int a[]={1,0,0,1,1,0,1,0,1,1,1};
    int a[]={0,1,1,1,0,0};
    int m=1;
    int n=sizeof(a)/sizeof(a[0]);
    int x=fun(a,n,m);

    printf("x:%d",x);
}
