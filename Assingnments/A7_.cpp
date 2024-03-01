#include<iostream>
#include "A4_SLL.cpp"
using namespace std;

int countList(SLL &s){
    node *t;
    t=s.getFirstNode();
    int count=1;
    while(t->next!=nullptr){
         count++;
         t=t->next;
    }
    return count;    
}

int main()
{
    SLL s1,s2;
    s1.insertAtLast(10);
    s1.insertAtLast(20);
    s1.insertAtLast(30);
    s1.insertAtLast(40);
    s1.insertAtLast(50);
    s1.insertAtLast(60);
    cout<<"S1: "<<countList(s1)<<endl;
    s1.printList();
    return 0;
}