#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

typedef struct name
{
    char naam[10];
    int age;
}name ;


using namespace std;
int main()
{
struct name a,*p;
p=&a;
cin>>p->naam;
cin>>p->age;

}
