#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class CDLL
{
    private:
        node *start;
    public:
        CDLL();
        void insertAtFirst(int);
        void insertAtLast(int);
};
void CDLL::insertAtLast(int data){
    node *n=new node;
    if(start){
        n->prev = start->prev;
        n->next = start;
        n->next->prev = n;
        n->prev->next = n;
    }
    else{
        n->prev=n;
        n->next=n;
        start=n;
    }
}
void CDLL::insertAtfirst(int data){
    node *n=new node;
    n->item=data;
    if(start){
        n->prev=start->prev;
        n->next=start;
        start->prev=n;
        if(start->next==start)
            start->next=n;
        n->prev->next = n;
        start=n;
    }
    else{
        n->prev=n;
        n->next=n;
        start=n;
    }
}
CDLL::CDLL(){
    start=NULL;
}