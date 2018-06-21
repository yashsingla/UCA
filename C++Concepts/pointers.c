//2d array and pointers
#include<stdio.h>
#include<stdlib.h>


int main()
{
    int b[][3]={{8,2,3},
                 {4,5,6}};

    int (*p)[3]=b;

    printf("&b:%d\n",&b);
    printf("b:%d\n",b);
    printf("&b[0]:%d\n",&b[0]);
   printf("*b:%d\n",*b);
   printf("b[0]:%d\n",b[0]);
   printf("&b[0][0]:%d\n",&b[0][0]);

   printf("\n\nb+1:%d\n",(b+1));
    printf("&b[1]:%d\n",&b[1]);
   printf("*(b+1):%d\n",*(b+1));
   printf("b[1]:%d\n",b[1]);
   printf("&b[1][0]:%d\n",&b[1][0]);
   printf("**b+1:%d\n",**b+1);

   printf("\n\np:%d\n",p);
   printf("&p[0]:%d\n",&p[0]);
   printf("*p:%d\n",*p);
  printf("p[0]:%d\n",p[0]);
   printf("&p[0][0]:%d\n",&p[0][0]);
}

/*
b[i][j]=*(b[i]+j);
       =*(*(b+i)+j);
*/
