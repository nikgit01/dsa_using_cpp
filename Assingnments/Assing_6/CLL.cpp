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
};
void CLL::deleteLast(){

}
void CLL::deleteFirst(){
    if(last){
        node *temp;
        temp=last->next;
        last->next=temp->next;
        delete temp;
        last=NULL;
    }
}
node* CLL::search(int data){
    node *t,*ptr;
    t=last->next;
    ptr=last->next;
    while(t->next!=ptr){
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}
void CLL::insertAtLast(int data){
    node *n=new node;
    n->item= data;
    if(last)
        n->next=last->next;
    else
        last=n;
    last->next=n;
    last=n;
}
void CLL::insertAtFirst(int data){
    node *n=new node;
    n->item=data;
    if(last)
        n->next=last->next;
    else
        last=n;
    last->next=n;
}
CLL::CLL(){last=NULL;}