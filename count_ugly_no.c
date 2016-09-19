#include<stdio.h>

unsigned min(unsigned  a,unsigned  b,unsigned  c);

unsigned  count_ugly(int n)
{
    unsigned *count;
    count=(unsigned*)malloc(sizeof(unsigned)*n);
    count[0]=1;
    unsigned i2=0,i3=0,i5=0,i;

    unsigned  multiple_2=2;
    unsigned  multiple_3=3;
    unsigned  multiple_5=5;
    unsigned next_ugly=1;
    for(i=1;i<n;i++)
    {
       next_ugly=min(multiple_2,multiple_3,multiple_5);
       count[i]=next_ugly;

      if(next_ugly==multiple_2)
      {
          i2=i2+1;
          multiple_2=count[i2]*2;
      }


      if(next_ugly==multiple_3)
      {
          i3=i3+1;
          multiple_3=count[i3]*3;
      }


      if(next_ugly==multiple_5)
      {
          i5=i5+1;
          multiple_5=count[i5]*5;
      }

   }//for end

 return next_ugly;

}

 unsigned min(unsigned  a,unsigned  b,unsigned  c)
   {
       if(a<=b)
       {
           if(a<=c)
            return a;
            else
             return c;

       }

       if(b<=c)
         return b;
       else
        return c;

   }


int main()
{   unsigned x;
    printf("calling ugly no. function:");
    x=count_ugly(150);

    printf("150th ugly number is:%d",x);
}
