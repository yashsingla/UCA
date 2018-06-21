#include<iostream>
#include<string.h>
using namespace std;

int isVowel(char s)
{
if(s=='a'||s=='u'||s=='o'||s=='i'||s=='e')
    return 1;
return 0;
}

int isChar(char s)
{
if(s>'a'&&s<'z')
    return 1;
return 0;
}


char GoodBad(char str[],int n)
{
    if(n<=0)
        return 'm';
  int i,vc=0,cc=0,ccM=0,vcM=0;
  char x='\0';

  for(i=0;i<n;i++)
  {
      if(isChar(str[i]))
      {
          if(isVowel(str[i]))
          {
              vc++;
              if(vcM>0)
                vcM++;
              cc=ccM=0;

          }
          else{
                cc++;
              if(ccM>0)
                ccM++;
              vc=vcM=0;

          }
      }
      else
        if(str[i]=='?')
      {
          vcM+=vc+1;
          ccM+=cc+1;
          vc=cc=0;
      }

      if(cc>=5||vc>=3)
        x='b';

        if(ccM>=5||vcM>=3)
        x='m';
  }

   if(x=='\0')
      x='g';

   return x;
}

int main()
{
char str[]="abcd?eg";
int n=strlen(str);
cout<<GoodBad(str,n);

}
/* test cases
abc : GOOD
abcdefghjkl : BAD
abcd?eg : GOOD
abcd?eij : MIXED
abcd?keij : MIXED
abcd??eij : MIXED
kbd??ej : MIXED
kbd?e? : MIXED
?aa : MIXED
 : GOOD
jk : GOOD
*/
