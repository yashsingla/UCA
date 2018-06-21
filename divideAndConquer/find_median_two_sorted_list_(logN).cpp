/* time complexity: O(logN)
here size of both arrays are same
*/
#include<iostream>

using namespace std;

int mini(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}

int maxi(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}


void wrapper(int a1[],int a2[],int n)
{
    int l1=0,r1=n-1,m1;
    int  l2=0,r2=n-1,m2;
    int n1=n,flag=0;
    while(n1>2)
    {
        int mid1=(l1+r1)/2;
        int mid2=(l2+r2)/2;

        if(n1%2==0)
        {
           m1=(a1[mid1]+a1[mid1+1])/2;
           m2=(a2[mid2]+a2[mid2+1])/2;

              if(m1==m2)
              {
                  cout<<"median is:"<<m1;
                  flag=1;
                  break;
              }
            if(m1<m2)
            {
                l1=mid1+1;
                r2=mid2;
            }
            else
                if(m2<m1)
            {
                r1=mid1;
                l2=mid2+1;
            }
            n1=r2-l2+1;
        }
        else
        {
            m1=a1[mid1];
           m2=a2[mid2];

              if(m1==m2)
              {
                  cout<<"median is:"<<m1;
                  flag=1;
                  break;
              }
            if(m1<m2)
            {
                l1=mid1;
                r2=mid2;
            }
            else
                if(m2<m1)
            {
                r1=mid1;
                l2=mid2;
            }
        n1=r2-l2+1;
        }
    } // while ends


     cout<<"mdeian is:"<<double(maxi(a1[l1],a2[l2])+mini(a1[r1],a2[r2]))/2;

}// wrapper function ends

 int main()
 {
     // when arrays are of same size
     int a1[]={1,3,5,8,10,11};
     int a2[]={2,4,7,9,12,13};
     int n=sizeof(a1)/sizeof(a1[0]);

     wrapper(a1,a2,n);
}
