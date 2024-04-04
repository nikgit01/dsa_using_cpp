#include<iostream>
using namespace std;
int main()
{
    for(int i=0; i<=6; i++){
        for(int j=i-1; j<6; j++){
            cout<<"* ";
        }
        cout<<" ";
        cout<<endl;
    }
    
    return 0;
}