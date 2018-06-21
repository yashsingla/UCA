//http://stackoverflow.com/questions/21749241/explain-to-me-where-the-x-in-hexadecimal-0xf0-comes-from
// (read for concept clarity on hexa octa decimal base)

#include<stdio.h>
#include<stdlib.h>

unsigned char swap(unsigned char x)
{
    return ((x&0x0f)<<4)|((x&0xf0)>>4);
}


int main()
{
   unsigned char c=100;
    printf("ans:%u",swap(c)); //printf("ans:%d",swap(c)); both are same
}

/* second solution by me
int main()
{
     char c=100,a,b;
    a=c<<4;
    b=c>>4;
    printf("ans:%u",a|b);

}*/
