#include<iostream>
#include "SLL.cpp"
using namespace std;
int countList(){
    node *t;
    t=start;
    int count=0;
    while(t->next!=nullptr)
        count++;
    t=t->next;
    return t;  
}
