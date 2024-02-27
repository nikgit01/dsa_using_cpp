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
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node *);
        ~CDLL();
};
CDLL::~CDLL()
{
    while(start)
        deleteFirst();
}
void CDLL::deleteNode(node *temp)
{
    if(temp)
    {
        if(start==start->next)
            start=NULL;
        else
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            if(start==temp)
                start=temp->next;
        }
        delete temp;
    }
}
void CDLL::deleteLast()
{
    node *r;
    if(start)
    {
        if(start->prev==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            r=start->prev;
            r->prev->next=start;
            start->prev=r->prev;
            delete r;
        }
    }
}
void CDLL::deleteFirst()
{
    node *r;
    if(start)
    {
        r=start;

        r->next->prev=r->prev;
        r->prev->next=r->next;
        if(start->next==start)
            start=NULL;
        else
            start=r->next;
        delete r;
    }
}
void CDLL::insertAfter(node *temp,int data)
{
    
    if(temp)
    {
        node *n=new node;
        n->item=data;
        n->prev=temp;
        n->next=temp->next;
        temp->next->prev=n;
        temp->next=n;
    }
}
node* CDLL::search(int data)
{
    node *t;
    t=start;
    if(t)
    {
        do
        {
         if(t->item==data)
            return t;
         t=t->next;
        }while(t!=start);
    }
    return NULL;
}
void CDLL::insertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->next=n;
        n->prev=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
    }
}
void CDLL::insertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->next=n;
        n->prev=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        start->prev->next=n;
        start->prev=n;
        start=n;
    }
}
CDLL::CDLL()
{
    start=NULL;
}