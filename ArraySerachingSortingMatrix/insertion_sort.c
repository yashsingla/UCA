#include<stdio.h>

int main()
{
    int a[]={10,9,8,7,6,5,4,3,2,1},i=1;

    while(i<10)
    {
        int temp=a[i];
        int j=i;

        while(j>0&&a[j-1]>temp)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;



        i++;
    }

 for(i=0;i<10;i++)
        printf("%d",a[i]);
        printf("\n");

}
