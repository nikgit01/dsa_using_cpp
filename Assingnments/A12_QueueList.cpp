#include<iostream>
#include<stdio.h>
using namespace std;
struct node{
    int item;
    node *next;
};
class Queue{
    private:
        node *front, *rear;
    public:
        Queue();
        Queue(Queue &);
        void insert(int);
        bool isEmpty();
        node* getRear();
        node* getFront();
        void del();
        ~Queue();
        int count();
        void printQueue();
        Queue& operator=(Queue &);   
};
Queue& Queue::operator=(Queue &Q){   // this Function was not commpleted
    
}
void Queue::printQueue(){
    node *temp = front; // Create a temporary pointer for traversal
    while (temp) {
        cout << " " << temp->item;
        temp = temp->next; // Move the temporary pointer to the next node
    }
    cout << endl;
}
int Queue::count(){
    node *t;
    int c=0;
    t=front;
    while(t){
        c++;
        t=t->next;
    }
    return c;
}
Queue::~Queue(){
    while(!isEmpty())
        del();
}
void Queue::del(){
    node *r;
    if(!isEmpty()){
        r=front;
        front=front->next;
        if(front==NULL)
            rear=NULL;
        delete r;
    }
}
node* Queue::getFront(){
    return front;
}
node* Queue::getRear(){
    return rear;
}
bool Queue::isEmpty(){
    return rear==NULL;
}
void Queue::insert(int data){
    node *n;
    n=new node;
    n->item=data;
    n->next=NULL;
    if(isEmpty())
        front=rear=n;
    else{
        rear->next=n;
        rear=n;
    }
}
Queue::Queue(Queue &Q){
    front=rear=NULL;
    node *temp;
    temp=Q.front;
    while(temp){
        node *newNode=new node;
        newNode->item=temp->item;
        newNode->next=NULL;
        if(!front)
            front=rear=newNode;
        else{
            rear->next=newNode;
            rear=newNode;
        }
        temp=temp->next;
    }
}
Queue::Queue(){
    front=NULL;
    rear=NULL;
}
int main()
{
    Queue Q;
    Q.insert(20);
    Q.insert(40);
    Q.insert(60);
    Q.insert(80);
    // Q.printQueue();
    Q.del();
    Q.printQueue();
    Queue Q2=Q;
    Q2.printQueue();
    return 0;
}
