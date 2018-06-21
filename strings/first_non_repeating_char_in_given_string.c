//here time complexity is:O(n) but code can be improved(time complexity still O(N)) for
//reducing to scan array a,only once but not twice as in case below
#include<stdio.h>
#include<stdlib.h>
#define no_of_chars 256

int *count_char(char a[],int n,int *count)
{
    //int *count=(int *)calloc(sizeof(int),no_of_chars);
    int i;
    for(i=0;a[i]!='\0';i++)
        count[a[i]]++;

    return count;
}

int NonRepeating(char a[],int n)
{
int *count=(int *)calloc(sizeof(int),no_of_chars);

count=count_char(a,n,count);
int i,index=-1;
    for(i=0;a[i]!='\0';i++){
    if(count[a[i]]==1){
      index=i;
      break;
    }
    }
return index;
}

int main()
{
char a[]="geeksforgeeks";
int n=sizeof(a)/sizeof(a[0]);

int index=NonRepeating(a,n);
if(index==-1)
    printf("either all characters are repeating or string is empty");
else
    printf("first non repeating character is:%c",a[index]);
}
