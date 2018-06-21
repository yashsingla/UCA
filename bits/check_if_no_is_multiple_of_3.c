#include<stdio.h>

int ismultipleof3(int n)
{
    int odd=0,even=0;
    if(n<0)
        n=-n;
    if(n==0)
        return 1;
    if(n==1)
        return 0;

    while(n){
    if(n&1)
        odd++;
    n>>=1;

    if(n&1)
        even++;
    n>>=1;
    }

    return ismultipleof3(even-odd);
}

int main()
{
    int n=9;
  if(ismultipleof3(n))
    printf("yes");
  else
    printf("no");
}
