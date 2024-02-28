#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class CLL
{
    private:
        node *last;
    public:
        CLL();
        void insertAtFirst(int);
        void insertAtLast(int);
        node* search(int); 
        void deleteFirst();
        void deleteLast();
        void deleteNode(node *);
        void insertAfter(node*,int);
        ~CLL();
};
CLL::~CLL(){
    while(last)
        deleteLast();
}
void CLL::deleteNode(node *temp){
    if(temp){
        node *t;
        t=last->next;
        while(t->next!=temp)
            t=t->next;
        t->next=temp->next;
        if(t==temp)
            last=NULL;
        else if(temp==last)
                last=t;
        delete temp;
    }
}
void CLL::deleteLast(){
    if(last){
        node *t;
        t=last;
        while(t->next!=last)
            t=t->next;
        if(t==last){  // singal node
            delete last;
            last=NULL;
        }
        else{
            t->next=last->next;
            delete last;
            last=t;
        }
    }
}
void CLL::deleteFirst(){
    if(last){
        node *temp;
        temp=last->next;
        if(last->next==last)
            last=NULL;
        else
            last->next=temp->next;
        delete temp;
    }
}
void CLL::insertAfter(node *temp,int data){
    if(last){
        node *n=new node;
        n->item=data;
        n->next=temp->next;
        temp->next=n;
        if(temp=last)
            last=n;
    }
}
node* CLL::search(int data){
    if(last){
        node *t,*ptr;
        t=last->next;
        ptr=last->next;
        while(t->next!=ptr){
            if(t->item==data)
                return t;
            t=t->next;
        }
    }
    return NULL;
}
void CLL::insertAtLast(int data){
    node *n=new node;
    n->item= data;
    if(last){
        n->next=last->next;
        last->next=n;
        last=n;
    }
    else{
        n->next=n;
        last=n;
    }
}
void CLL::insertAtFirst(int data){
    node *n=new node;
    n->item=data;
    if(last){
        n->next=last->next;
        last->next=n;
    }
    else{
        n->next=n;
        last=n;
    }
}
CLL::CLL(){last=NULL;}
