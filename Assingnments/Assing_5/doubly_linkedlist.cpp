#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class DLL
{
    private: 
        node *start;
    public:
        DLL();
        void insertFirst(int);
        void insertLast(int);
        node* search(int);
        void insertAfterNode(node *,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node *);
        ~DLL();
};
DLL::~DLL(){
    while(start!=NULL)
        deleteFirst();
}
void DLL::deleteNode(node *ptr){
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    delete ptr;
}
void DLL::deleteLast(){
    node *t;
    t=start;
    if(start==NULL)
        cout<<"\n UnderFlow\n";
    else{
        while(t->next!=NULL)
            t=t->next;
        t->prev->next=NULL;
        delete t;
    }
}
void DLL::deleteFirst(){
    node *t;
    t=start;
    if(start==NULL)
        cout<<"\nUnderFlow";
    start=t->next;
    t->next->prev=NULL;
    delete t;  
}
void DLL::insertAfterNode(node *ptr,int data){
    node *n=new node;
    n->item=data;
    n->prev=ptr;
    n->next=ptr->next;
    n->next->prev=n;
    ptr->next=n;
}
node* DLL::search(int data){
    node *t;
    t=start;
    while(t!=NULL){
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
void DLL::insertLast(int data){    // Required modification
    node *t;
    node *n=new node;
    n->item=data;
    n->next=NULL;
    t=start;
    while(t->next!=NULL)
        t=t->next;
    n->prev=t;
    t->next=n;
}
void DLL::insertFirst(int data){
    node *n=new node;
    n->item=data;
    n->prev=NULL;
    n->next=start;
    if(start)
        start->prev=n;
    start=n;
}
DLL::DLL(){
    start=NULL;
}