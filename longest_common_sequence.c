#include<stdio.h>

int main()
{
    char a[]="ABCDGH";
    char b[]="AEDFHR";
    char c[10];


    int i,j,k=0;

    for(i=0;i<strlen(a);i++)
    {
        for(j=0;j<strlen(b);j++)
        {
            if(a[i]==b[j])
            {
                c[k]=a[i];
                k++;
                b[j]='-';
                break;
            }

        }
    }
c[k+1]='/0';
    printf("%s",c);

}
