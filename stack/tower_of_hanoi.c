/*
The time complexity of TOH can be calculated by formulating number of moves.

We need to move the first N-1 disks from Source to Auxiliary and from Auxiliary to Destination, i.e. the
first N-1 disks requires two moves. One more move of last disk from Source to Destination. Mathematically it can be -1
defined recursively.

T(N) = 2T(N-1) + 1

We can easily solve the above recursive relation (2POWER(n))-1, which is exponential.
*/

#include<stdio.h>
#include<stdlib.h>

void tower(int n,char src,char aux,char dest)
{
    if(n==1){
        printf("Move disc 1 from src:%c to dest:%c using aux:%c\n",src,dest,aux);
    return;
    }
    tower(n-1,src,dest,aux);
    printf("Move disc %d from src:%c to dest:%c using aux:%c\n",n,src,dest,aux);
    tower(n-1,aux,src,dest);
}

int main()
{
    int n=4;
    tower(n,'S','A','D');
}
