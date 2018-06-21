#include<iostream>
#include<list>

using namespace std;
int main()
{
    list<int>l1(3);
    list<int>l2(6);
    list<int>l3;
                                                      //size() and empty() function
    cout<<"size1:"<<l1.size()<<endl;
    cout<<"size2:"<<l2.size()<<endl;
    cout<<"size3:"<<l3.size()<<endl;
    cout<<"if list-3 is Empty?:"<<l3.empty()<<endl;

    //---------------------------------------------------------

    list<int>l4; //list<int>l4{1,2,3,4};
    list<int>l5; //list<string>{"hello","bye","yash"};

    int i,num;

cout<<"list 1:"<<endl;

    for(i=0;i<5;i++)
    {
        cout<<"num:";
        cin>>num;
        l4.push_back(num);
        cout<<endl;
   }

 cout<<"list 2:"<<endl;

     for(i=0;i<5;i++)
    {
        cout<<"num:";
        cin>>num;
        l5.push_front(num);

        cout<<endl;

            }
cout<<endl;
cout<<"print list 1:";
    list<int>::iterator k=l4.begin();

       while(k!=l4.end())
       {
           cout<<*k<<" ";
           k++;
       }
cout<<endl<<endl;
cout<<"print list 2:";

 k=l5.begin();

       while(k!=l5.end())
       {
           cout<<*k<<" ";
           k++;
       }
 //------------------------------------------------------------
cout<<endl<<endl<<"first element of list-4:"<<l4.front();
cout<<endl<<endl<<"first element of list-5:"<<l5.front();
 //----------------------------------------------
 cout<<endl<<endl<<"sorted list-5:";
 l5.sort();
                                        // sort() function
  k=l5.begin();
       while(k!=l5.end())
       {
           cout<<*k<<" ";
           k++;
       }
//-----------------------------------------------------------------------------------
     cout<<endl<<endl<<"reversed list-5:";
 l5.reverse();
                                        // reverse() function
  k=l5.begin();
       while(k!=l5.end())
       {
           cout<<*k<<" ";
           k++;
       }

//-------------------------------------------------------------------------------------
cout<<endl<<endl<<"merging of L4 and L5:";
l5.merge(l4);
 k=l5.begin();
                                            // merge() function
       while(k!=l5.end())
       {
           cout<<*k<<" ";
           k++;
       }
//-------------------------------------------------------------
l5.clear();
cout<<endl<<endl<<"size of list-5 after clearing it:"<<l5.size()<<endl;
}//main ends
