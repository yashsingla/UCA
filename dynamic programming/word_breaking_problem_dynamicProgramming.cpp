#include<iostream>
#include<string>
#include<cstring>

using namespace std;

bool diction(string k)
{
     string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};

    int n=sizeof(dictionary)/sizeof(dictionary[0]);

    int i;

    for(i=1;i<=n;i++)
    if(dictionary[i].compare(k)==0)
        return true;

return false;
}

bool word_break(string s)
{
      int i,j;
      int n=s.size();
    int w[n+1];
    memset(w,0,sizeof(w));

  for(i=1;i<=n;i++)
  {
          if(w[i]==false&&diction(s.substr(0,i)))
             w[i]=true;

            if(w[i]==true){
           if(i==n)
            return true;
       for(j=i+1;j<=n;j++)
         {
             if(w[j]==false&&diction(s.substr(i,j-1)))
             w[j]=true;

             if(j==n&&w[j]==true)
                return true;
         }//inner for ends
     } //if ends
  }//for ends
return false;
}

int main()
{
   if(word_break("ilike"))
    cout<<"yes"<<endl;
    else
   cout<<"No"<<endl;

   if(word_break("samsung"))
    cout<<"yes"<<endl;
    else
   cout<<"No"<<endl;
}
