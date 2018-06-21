#include <stdio.h>
#include <limits.h>

void print()
{
    char a[]="abcdef",i=0;
    while(a[i++]!='\0')
    {
        printf("i: %d\n",i);
        printf("x: %c\n\n",a[i]);
    }

}
int main()
{
    print();
}
