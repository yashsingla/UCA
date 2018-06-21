//time complexity:O(square_root of n)
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/*
int fun1(int n)
{
    int i;

    for(i=2;i<=(sqrt(n));i++){
        if(n%i==0){
         return 0;
         break;
    }}
return 1;

}
*/
int fun(int n)
{ int i;
    if(n<=1)return 0;
    if(n<=3)return 1;

    if(n%2==0||n%3==0)return 0;

    for(i=5;i*i<=n;i=i+6)
        if(n%i==0||n%(i+2)==0)
          return 0;
return 1;
}
int main()
{
    int n=58,i;

    if(fun(n)!=0)
     printf("true");
        else
    printf("false");
}

/*
We can do following optimizations:

1) Instead of checking till n, we can check till √n because a larger factor of n must be a multiple of smaller factor that
  has been already checked.

2) The algorithm can be improved further by observing that all primes are of the form 6k ± 1, with the exception of 2 and 3.
 This is because all integers can be expressed as (6k + i) for some integer k and for i = ?1, 0, 1, 2, 3, or 4;
 2 divides (6k + 0), (6k + 2), (6k + 4); and 3 divides (6k + 3). So a more efficient method is to test
  if n is divisible by 2 or 3, then to check through all the numbers of form 6k ± 1.
*/
