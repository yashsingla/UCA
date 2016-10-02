// this is most efficient method ...it can also be done with level traversal

#include<stdio.h>

int set_bit(int n)
{  int count=0;
    while(n)
    {
    n&=n-1;
    count++;
    }
    return count;
}

int profession(int level,int pos)
{
    int count=set_bit(pos-1);
    if(count%2==0)
        return 1;
    else
        return 0;
}

int main()
{
    int level=4,pos=4;

    int c=profession(level,pos);
    if(c==1)
        printf("Engineer");
    else
        printf("Doctor");
}
