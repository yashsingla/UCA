//time complexity:O(n)
//space complexity:O(0)
//This is more optimized version than stack as space complexity is zero;
#include<stdio.h>
#include<stdlib.h>

int mat[4][4]={ {0,0,0,1},
                {0,0,0,1},
                {0,0,0,1},
                {0,0,0,0},
             };

int know(int a,int b)
{
    return mat[a][b];
}

int findCelebrity(int n)
{
    int a=0,b=n-1;
    int i;
    while(a<b)
    {
        if(know(a,b))
            a++;
    else
            b--;

    }

    for(i=0;i<n;i++)
        if((i!=a)&& (know(a,i)||!know(i,a)) )
        return -1;
    return a;
}


int main()
{
int n=4;
int x=findCelebrity(n);

if(x==-1)
    printf("there is no celebrity");
else
    printf("celebrity is:%d",x);

}
