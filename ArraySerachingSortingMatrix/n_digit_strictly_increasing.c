#include<stdio.h>
#include<stdlib.h>

void increasing(int start,char a[],int n,int index)
{  int i;
    if(index==n)
    {//a[index]='\0';
    printf("%s\t",a);
    return;
    }
/*
   for(i=start;i<=9;i++)
   {
       char b[10],c[10];
       itoa(i,c,10);
       strcat(a,c);
       strcpy(b,a);
      increasing(i+1,b,n-1);

   }  */


   for(i=start;i<=9;i++)
   {
       a[index]='0'+ i;
       increasing(i+1,a,n,index+1);
   }
}


int main()
{
    int n=3;
    char  a[10]="";
    increasing(0,a,n,0);

    return 0;
}

