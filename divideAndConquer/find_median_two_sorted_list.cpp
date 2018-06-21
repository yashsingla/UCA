/*time complexity: O(N)
now if sizes of both the arrays are different (m,n) then,we stop at (m+n)/2 th element
*/
#include<iostream>

 using namespace std;

void wrapper(int a1[],int a2[],int n)
{
    int temp[2*n];
     int i=0,j=0,k=-1,cnt=0,flag=0;

    while(i<n&&j<n)
    { //main while starts
        if(a1[i]<a2[j]){
        temp[++k]=a1[i++];
        cout<<temp[k]<<" ";


        if(k==n){
             flag=1;
            break;
        }

        }

        else

        if(a1[i]>a2[j]) {

        temp[++k]=a2[j++];
      cout<<temp[k]<<" ";

        if(k==n){
             flag=1;
            break;
        }

        }
   }// main while ends
          if(flag==1)
            cout<<"median found is:"<<double(temp[k]+temp[k-1])/2;
      else
      {
          while(i<n)
          { //else while 1st starts
              temp[++k]=a1[i++];
              if(k==n){
            cout<<"median found is:"<<double(temp[k]+temp[k-1])/2;
            break;
        }
          } //else while 1st ends


         while(j<n)
          { //else while 2nd starts

              temp[++k]=a2[j++];
              if(k==n){
            cout<<"median found is:"<<double(temp[k]+temp[k-1])/2;
            break;
        }

          }//else while 2nd ends

      }
}


 int main()
 {
     // when arrays are of same size
     int a1[]={1,3,5,8,10,11};
     int a2[]={2,4,7,9,12,13};
     int n=sizeof(a1)/sizeof(a1[0]);

     wrapper(a1,a2,n);
}
