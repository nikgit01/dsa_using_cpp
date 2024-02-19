#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class SLL
{
    private:  
        node *start;
    public:
        SLL();
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node *,int);
        void deleteFirst();
        void deleteLast();
};
void SLL::deleteLast(){
    node *t;
    if(start==NULL){
        cout<<"\nUnderflow\n";
    }
    else if(start->next==NULL){
        delete start;
        start=NULL;
    }
    else{
        t=start;
        while(t->next->next!=NULL)
            t=t->next;
        delete t->next;
        t->next=NULL;
    }

}
void SLL::deleteFirst(){
    node *t;
    if(start){
        t=start;
        start=start->next;
        delete t;
    }
}
void SLL::insertAfter(node *ptr,int data){
    node *n=new node;
    n->item=data;
    n->next=ptr->next;
    ptr->next=n; 
}
node* SLL::search(int data){
    node *t;
    t=start;
    while(t!=NULL){
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
void SLL::insertAtLast(int data){
    node *t;
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL)
        start=n;
    else{
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
    }
}
void SLL::insertAtStart(int data){
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}
SLL::SLL(){
    start=NULL;
}