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
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        ~DLL();
};
DLL::DLL() { start=NULL;}
DLL::~DLL()
{
    while(start)
        deleteFirst();
}
void DLL::deleteNode(node* temp)
{
    if(temp->prev)
        temp->prev->next=temp->next;
    else
        start=temp->next;
    if(temp->next)
        temp->next->prev=temp->prev;
    delete temp;
}
void DLL::deleteLast()
{
    if(start)
    {
        node *t;
        t=start;
        while(t->next!=NULL)
            t=t->next;
        if(t->prev)
            t->prev->next=NULL;
        else
            start=NULL;
        delete t;
    }
}
void DLL::deleteFirst()
{
    if(start)
    {
        node *r=start;
        start=start->next;
        if(r->next)
            start->prev=NULL;
        delete r;
    }
}
void DLL::insertAfter(node* temp,int data)
{
    if(temp)
    {
        node *n=new node;
        n->item=data;
        n->prev=temp;
        n->next=temp->next;
        if(temp->next)
            temp->next->prev=n;
        temp->next=n;
    }
}
node* DLL::search(int data)
{
    node *t;
    t=start;
    while(t!=NULL)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
void DLL::insertAtLast(int data)
{
    node *t;
    node *n=new node;
    n->next=NULL;
    n->item=data;
    if(start==NULL)
    {
        n->prev=NULL;
        start=n;
    }
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        n->prev=t;
        t->next=n;
    }

}
void DLL::insertAtStart(int data)
{
    node *n=new node;
    n->prev=NULL;
    n->item=data;
    n->next=start;
    if(start)
        start->prev=n;
    start=n;
}