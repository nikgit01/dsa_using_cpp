#include<iostream>
using namespace std;
void Rstar(){
    int n;
    cout<<"Enter the number of Row: "<<endl;
    cin>>n;
    for(int i=0; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
    cout<<" ";
    cout<<endl;
    }
}
int main()
{
    for(int i=0; i<=6; i++){
        for(int j=i+1; j<6; j++){
            cout<<"* ";
        }
        cout<<" ";
        cout<<endl;
    }
    Rstar();
    
    return 0;
}