/*
n=1 (0000..01)
result shuld be number  with bits (1000..0)=2147483648

On a machine with size of unsigned
bit as 32. Reverse of 0....001 is
100....0.
*/

#include<stdio.h>
#include<stdlib.h>

unsigned int fun(int n)
{
  unsigned int no_of_bits=sizeof(n)*8;
  int i;
  unsigned int reverse=0;
  for(i=0;i<no_of_bits;i++)
  {
      if(n&(1<<i))
      reverse|=1<<((no_of_bits-1)-i);
  }
  return reverse;
}

int main()
{
    int n=1;
printf("reversed bit number:%d",fun(n));
}
