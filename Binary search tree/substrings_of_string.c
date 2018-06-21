#include<stdio.h>
#include<stdlib.h>


/*void print(char a[],int n)
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
          printf("%s\n",sub);}
      }
  }
}*/

void print(char a[],int l,int n)
{
    int i;
    char sub[10];
    int depth=0;
    for(i=l;i<n;i++)
    {
    sub[depth]=a[i];
    sub[depth+1]='\0';
    printf("%s ",sub);
    depth++;
    print(a,i+1,n);
    }

}

int main()
{
    char a[]="the";
    int n=strlen(a);
    //printf("%d",n);

    print(a,0,n);
}
