#include "ass_2.cpp"
#include<iostream>
using namespace std;
int main()
{
    ExtentdedArray obj(5);
    obj.append(20);
    obj.append(70);
    obj.append(30);
    obj.append(10);
    cout<<"Greatest element is :"<<obj.greatest();


    cout<<endl;
    return 0;
}