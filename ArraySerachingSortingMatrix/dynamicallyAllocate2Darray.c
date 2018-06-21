#include<stdio.h>
#include<stdlib.h>
#define r 3
#define c 4
//----------------------------------------------------------------
void methodOne()
{
    int *arr=(int *)malloc(r*c*sizeof(int));
    int i,j,count=0;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            *(arr+i*c+j)=count++;  // i=0,c=4 ,i*c=0 print 0,1,2,3
                                   //  i=1,c=4 i*c=4 print 0+4,1+4,2+4,3+4
                                   //  i=2,c=4 i*c=8 print 0+8,1+8,2+8,3+8
         }
    }

  printf("print methodOne: ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",*(arr+i*c+j));
        }
    }
}
//-------------------------------------------------------------------
void methodTwo()
{
    /*
    int *arr[r] or  // static
    int **arr;
     arr=(int**)malloc(r*sizeof(int*)); //dynamic
     both are same thing
    */
    int *arr[r],i;
    for(i=0;i<r;i++)
     arr[i]=(int*)malloc(c*sizeof(int));

    int j,count=0;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            arr[i][j]=count++;
        }
    }

  printf("print methodTwo: ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",arr[i][j]);
        }
    }
}
//--------------------------------------------------------------
void methodThree()
{
    int **arr,i;// the only difference between method2 and method3 is we have created array of pointers in 2 statically and in three dynamically
     arr=(int**)malloc(r*sizeof(int*));

     for(i=0;i<r;i++)
     arr[i]=(int*)malloc(c*sizeof(int));


    int j,count=0;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            arr[i][j]=count++;
        }
    }

  printf("print methodThree: ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",arr[i][j]);
        }
    }
}

//---------------------------------------------------------------

int main()
{
//methodOne();
methodTwo();
//methodThree();
//methodFour();
}
