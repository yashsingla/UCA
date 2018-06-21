#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define no_of_chars 256

struct node
{
    int count;
    int index;
};

int *count_char(char a[],int n,struct node *count)
{
    //int *count=(int *)calloc(sizeof(int),no_of_chars);
    int i;
    for(i=0;a[i]!='\0';i++){
        count[a[i]].count++;

    if(count[a[i]].count==1)
        count[a[i]].index=i;
   }

    return count;

}

int NonRepeating(char a[],int n)
{
struct node *count=(struct node*)calloc(sizeof(struct node),no_of_chars);

 count=count_char(a,n,count);
int i,result=INT_MAX;
    for(i=0;a[i]!='\0';i++){
    if(count[a[i]].count==1&&count[a[i]].index<result){
      result=count[a[i]].index;
    }
    }
return result;
}


int main()
{
char a[]="geeksffooorrgeeks";
int n=sizeof(a)/sizeof(a[0]);

int index=NonRepeating(a,n);
if(index==INT_MAX)
    printf("either all characters are repeating or string is empty");
else
    printf("first non repeating character is:%c",a[index]);
}
