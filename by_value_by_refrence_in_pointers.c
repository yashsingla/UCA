#include<stdio.h>
#include<stdlib.h>
void swap(int **x,int **y)
{
    int temp=(**x);
    (**x)=(**y);
    (**y)=temp;
}

void swap1(int *x,int *y)
{
int temp=*x;
   (*x)=(*y);
   (*y)=temp;
}

int main()
{
    int a=2,b=3;
    printf("before swap:\na:%d\tb:%d",a,b);
    int *x=&a,*y=&b;
    int **l=&x,**m=&y;
    //swap(&x,&y);
    swap(l,m);

    printf("\n\nAfter swap(call  by refrence):\na:%d\tb:%d",a,b);
    swap1(*l,*m);
    printf("\n\nAfter swap1(call by value):\na:%d\tb:%d\n\n",a,b);

}
