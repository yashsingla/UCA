#include<stdio.h>
#include<math.h>
                        //time complexity:O(n)
int main()
{
    int n;
    printf("n:");
    scanf("%d",&n);

    int k=1,i=1,j;
    while(k<=n)
    {  j=0;
       while(j<i)
       {
           //int x=pow(2,i)+pow(2,j);
           int x= (1<<i) + (1<<j);
           printf("%d\n",x);
           j++;
           k++;
           if(k>n)
            break;
       }
       i++;
    }

}
