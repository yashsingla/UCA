/*
We can use a Queue to store the current tour. We first enqueue first petrol pump to the queue, we keep enqueueing petrol pumps
till we either complete the tour, or current amount of petrol becomes negative. If the amount becomes negative, then we keep
dequeueing petrol pumps till the current amount becomes positive or queue becomes empty.
*/
#include<stdio.h>
#include<stdlib.h>

struct truck
{
    int petrol;
    int distance;
};

int fun(struct truck a[],int n)
{
    int start=0;
    int end=1;

    int pet=a[start].petrol-a[start].distance;

    while(end!=start||pet<0)
    {
        while(pet<0&&start!=end)
        {
            pet -= a[start].petrol - a[start].distance; // dequeue
            start=(1+start)%n;

            if(start==0)
                return -1;
        }
        pet+=a[end].petrol-a[end].distance; //enqueue
        end=(1+end)%n;
    }
    return start;
}

int main()
{
    struct truck a[]={{6,4},{3,6},{7,3}};
    int n=sizeof(a)/sizeof(a[0]);

    int index=fun(a,n);
    if(index==-1)
        printf("no solution");
    else
        printf("start:%d",index);
}
