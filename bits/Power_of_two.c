// to find if number is power of two by counting set bits method
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ispoweroftwo(unsigned long long int n)
{  unsigned long long int temp;

        unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    if(count==1)
        return 1;
    else
        return 0;
}

int main() {
  unsigned long long int n=4095;

  if(ispoweroftwo(n)==1)
    printf("yes");
  else
    printf("No");
}
