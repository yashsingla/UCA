#include<stdio.h>
#include<stdlib.h>

void print(char a[],int n)
{  char sub[10];
    int i,j,c,k;

  for(i=1;i<=n;i++)
  {
      for(j=0;j<n;j++)
      {
          c=0,k=j;

        while(c<i)
        {
          sub[c]=a[k];
          c++,k++;
        }  if(strlen(sub)==i){
          sub[i]='\0';
          if(pallindrome(sub,c))
            printf("%s\n",sub);}
      }
  }
}//function ends

int pallindrome(char a[],int n)
{
    int i,j,p=0;

    for(i=0,j=n-1;i<=j;j--,i++)
        if(a[i]!=a[j])
           p=1;

    if(p==0)
        return 1;
    else
        return 0;
        //printf("%s\n",a);

}

int main()
{
    char a[]="geeks";
    int n=strlen(a);
    //printf("%d",n);

    print(a,n);
    //pallindrome(a,n);
}



