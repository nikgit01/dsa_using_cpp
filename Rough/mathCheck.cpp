#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int x=1235;
    int modul,div,oddOrEven;
    modul=x%10;  //Giving the last last value
    div=x/10;    // discard the last value
    oddOrEven=x%2; // check the number is odd or even in ( 0 or 1)
    cout<<endl<<"moduls: "<<modul<<endl<<"div: "<<div<<endl<<"odd Or Even: "<<oddOrEven;
    return 0;
}