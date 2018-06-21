#include<iostream>
#include<string>

using namespace std;

char getRoman(int x)
{
    switch(x)
    {
    case 1000: return 'M';
    case 500: return 'D';
    case 100: return 'C';
    case 50: return 'L';
    case 10: return 'X';
    case 5: return 'V';
    case 1: return 'I';
    default:return -1;
    }
}

void IntegerToRoman(int num, string &s)
{
    int div=1;

    while(num>div)
        div=div*10;

    div=div/10;
int temp=num;
    while(temp)
    {
        int val=temp/div;

        if(val<=3)
        {
            char ch=getRoman(div);
            while(val>=0)
            {
                s=s+ch;
                val--;
            }
        }
        else
            if(val==4)
        {
           s=s+getRoman(div);
           s=s+getRoman(div*5);
        }
        else
            if(val>=5&&val<=8)
        {
           s=s+getRoman(div*5);
           s+=getRoman(div)*(val-5);
        }
        else
            if(val==9)
        {
            s=s+getRoman(div);
            s+=getRoman(div*10);
        }
        temp=temp%div;
        div=div/10;

    }

}

int main()
{
    int num=3449;
    string s="";

    IntegerToRoman(num,s);
    cout<<s;
}
