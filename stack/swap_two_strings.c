#include<stdio.h>
#include<stdlib.h>
/*
//if we are using character pointers to store strings
void fun(char **x,char **y)
{
    char (*z)=(*x);
    (*x)=(*y);low
    (*y)=(z);
}

int main()
{
    char *x="geeksquiz";
    char *y="geeksforgeeks";
    printf("%s\t%s\n",x,y);
    fun(&x,&y);
    printf("%s\t%s",x,y);
}
*/

//if we are using character array to store stings then swap data to two arrays be
//if we use character arrays for above method string will not be swapped and if we use
//pointer method for this it will show segmentation fault

void fun(char x[],char y[])
{
  char *temp = (char *)malloc((strlen(x) + 1) * sizeof(char));
  strcpy(temp, x);
  strcpy(x, y);
  strcpy(y, temp);
  free(temp);

}

int main()
{
    char x[]="geeksquiz";
    char y[]="geeksforgeeks";
    char *b=x;
    printf("%s ",b);
    //printf("%s\t%s\n",x,y);
    //fun(x,y);
    //printf("%s\t%s",x,y);
}
