// given a set of CHARS and a input string INPUT, find the minimum window in str which will contain all the characters in CHARS in O(N)
/*
In this approach,we start from the beginning of the array and move to right. As soon As we have a window with all the required characters, we slide the
window as much right as possible with all the required elements. If current window length is less than min length found till now, update min length.
Remember after 1st time we find the window, we only slide the window right i.e we always have the required elements..jus we need to find the minimum
window
*/
#include<iostream>
#include<string>
#include<limits.h>
#define MAX 256
using namespace std;

void wrapper(char input[],int n,char str[],int n1)
{
  int shouldFind[MAX]={0};
  int hasFound[MAX]={0};

  int i,j=0,cnt=0,min_window=INT_MAX,x,y;

   for(i=0;i<n1;i++)
    shouldFind[str[i]]++;

   for(i=0;i<n;i++)
   {
       //if(!shouldFind[input[i]])
        //continue;

       hasFound[input[i]]+=1;

       if(shouldFind[input[i]]>=hasFound[input[i]])
         cnt++;

       if(cnt==n1)
       { //if 1 starts
           while(shouldFind[input[j]]==0 || hasFound[input[j]]>shouldFind[input[j]])
                 {   if(hasFound[input[j]]>shouldFind[input[j]])
                            hasFound[input[j]]--;
                     j++;
                 }

                 if(min_window>(i-j+1))
                 {
                     min_window=i-j+1;
                     x=i;
                     y=j;
                 }

       }// if 1 ends
   }// main for ends
cout<<"min_window: "<<min_window<<", x: "<<x<<", y:"<<y<<endl;

}// function ends

int main()
{
    char input[]="this is a test string";
    int n=sizeof(input)/sizeof(input[0]);

    char str[]="tist";
    int n1=sizeof(input)/sizeof(input[0]);

    wrapper(input,n,str,n1);
}
