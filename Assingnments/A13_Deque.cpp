#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class Deque
{
    private:
        node *front, *rear;
    public:
        Deque();
        void insertAtFront(int);
        bool isEmpty();
        void insertAtRear(int);
        void deleteFront();
        void deleteRear();
        node* getFront();
        node* getRear();
        int printFront();
        int printRear();
        ~Deque();
};

Deque::~Deque(){
    while(front)
        deleteFront();
}
int Deque::printRear(){
    if(!isEmpty())
        return rear->item;
    else
        return -1;
}
int Deque::printFront(){
    if(!isEmpty())
        return front->item;
    else
        return -1;
}
node* Deque::getRear(){
    return rear;
}
node* Deque::getFront(){
    return front;
}
void Deque::deleteRear(){
    node *r;
    if(rear){
        r=rear;
        if(rear==front)
            rear=front=NULL;
        else{
        rear=rear->prev;
        rear->next=NULL;
        }
        delete r;
        }
}
void Deque::deleteFront(){
    node *temp;
    if(front){
        temp=front;
        if(front==rear)
            front=rear=NULL;
        else{
            front=front->next;
            front->prev=NULL;
        }
        delete temp;
    }
}
void Deque::insertAtRear(int data){
    node *n;
    n=new node;
    n->item=data;
    n->prev=rear;
    n->next=NULL;
    if(rear)
        rear->next=n;
    else
        front=n;
    rear=n;
}
bool Deque::isEmpty(){
    return rear==NULL;
}
void Deque::insertAtFront(int data){
    node *n;
    n=new node;
    n->item=data;
    n->next=NULL;
    n->prev=NULL;
    if(isEmpty())
        front=rear=n;
    else{
        n->next=front;
        front->prev=n;
        front=n;
    }
}
Deque::Deque(){
    front=rear=NULL;
}
int main()
{
    Deque d;
    d.insertAtRear(10);
    d.insertAtFront(20);
    d.insertAtFront(30);
    d.insertAtRear(40);
    cout<<endl<<d.printFront();
    cout<<endl<<d.printRear();
    return 0;
}