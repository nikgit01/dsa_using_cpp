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
        void insertAtStart(int);
        void insertAtLast(int);
        node* search(int);
        void insertAfter(node*,int);
        void deleteFirst();
        void deleteLast();
        void deleteNode(node*);
        ~CLL();
};
CLL::~CLL()
{
    while(last)
        deleteFirst();
}
void CLL::deleteNode(node *temp)
{
    if(temp)
    {
        node *t;
        t=last->next;
        while(t->next!=temp)
            t=t->next;
        t->next=temp->next;
        if(t==temp) //single node
            last=NULL;
        else if(temp==last) 
            last=t;
        delete temp;
    }    
}
void CLL::deleteLast()
{
    if(last)
    {
        node *t;
        t=last;
        while(t->next!=last)
            t=t->next;
        if(t==last)
        { //single node
            delete last;
            last=NULL;
        }
        else
        {
            t->next=last->next;
            delete last;
            last=t;
        }
    }
}
void CLL::deleteFirst()
{
    if(last)
    {
        node *r;
        r=last->next;
        if(last->next==last)
            last=NULL;
        else
            last->next=r->next;
        delete r;
    }
}
void CLL::insertAfter(node *temp,int data)
{
    if(last)
    {
        node *n=new node;
        n->item=data;
        n->next=temp->next;
        temp->next=n;
        if(temp==last)
            last=n;
    }

}
node* CLL::search(int data)
{
    node *t;
    if(last) //list is non empty
    {
        t=last->next;
        do 
        {
            if(t->item==data)
                return t;
            t=t->next;
        }while(t!=last->next);   
    }
    return NULL;
}
void CLL::insertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    if(last)
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
    else
    {
        n->next=n;
        last=n;
    }
}
void CLL::insertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    if(last)
    {  //when list is not empty
        n->next=last->next;
        last->next=n;
    }
    else
    {  //when list is empty
        n->next=n;
        last=n;
    }
}
CLL::CLL()
{
    last=NULL;
}
