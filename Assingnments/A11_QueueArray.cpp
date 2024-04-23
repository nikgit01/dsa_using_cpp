#include<iostream>
#include<stdio.h>
using namespace std;
class Queue
{
    private:
        int capacity;
        int front,rear;
        int* ptr;
    public:
        Queue(int);
        Queue(Queue &);
        void insert(int);
        bool isFull();
        bool isEmpty();
        int getRear();
        int getFront();
        void del();
        ~Queue();
        int count();
        Queue& operator=(Queue &);

};
Queue& Queue::operator=(Queue &Q){
    capacity=Q.capacity;
    front=Q.front;
    rear=Q.rear;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
    int n=Q.count();
    int i=Q.front;
        while(n){
            ptr[i]=Q.ptr[i];
            if(i==capacity-1)
                i=0;
            else   
                i++; 
            n--;
        }
}
int Queue::count(){
    if(isEmpty())
        return 0;
    else if(front<=rear)
        return rear-front+1;
    else
        return capacity-front+rear+1;
}
Queue::~Queue(){
    delete []ptr;
}
void Queue::del(){
    if(isEmpty())
        cout<<"\n Queue UnderFlow";
    else if(front==rear){
        front=rear=-1;
    }
    else if(front==capacity-1)
        front=0;
    else
        front++;
}
int Queue::getFront(){
    if(!isEmpty())
        return ptr[front];
    cout<<"\nQure is Empty";
    return -1;
}
int Queue::getRear(){
    if(!isEmpty())
        return ptr[rear];
    cout<<"\n Queue is Empty";
    return -1;
}
bool Queue::isEmpty(){
    return rear==-1;
}
bool Queue::isFull(){
    return front==0 && rear== capacity-1 || rear+1==front;
}
void Queue::insert(int data){
    if(isFull())
        cout<<"\n Queue Overflow";
    else if(isEmpty()){
        front=rear=0;
        ptr[rear]=data;
    }
    else if(rear==capacity-1){
        rear=0;
        ptr[rear]=data;
    }
    else{
        rear++;
        ptr[rear]=data;
    }
}
Queue::Queue(Queue &Q){
    capacity=Q.capacity;
    front=Q.front;
    rear=Q.rear;
    ptr=new int[capacity];     // Use in Deep copy 
    int n=Q.count();
    int i=Q.front;
    while(n){
        ptr[i]=Q.ptr[i];  // copy the elements
        if(i==capacity-1)   
            i=0;
        else
            i++;
        n--;  
    }

}
Queue::Queue(int cap){
    capacity=cap;
    front=-1;
    rear=-1;
    ptr=new int[cap];
}
int main() {
    // Create a queue with capacity 5
    Queue q(5);

    // Insert elements into the queue
    q.insert(10);
    q.insert(20);
    q.insert(30);

    // Display front and rear elements
    std::cout << "Front element: " << q.getFront() << std::endl;
    std::cout << "Rear element: " << q.getRear() << std::endl;

    // Delete an element from the queue
    q.del();

    // Display front and rear elements after deletion
    std::cout << "Front element after deletion: " << q.getFront() << std::endl;
    std::cout << "Rear element after deletion: " << q.getRear() << std::endl;

    // Test for queue overflow
    q.insert(40);
    q.insert(50);
    q.insert(60); // Queue overflow

    // Display front and rear elements after queue overflow
    std::cout << "Front element after overflow: " << q.getFront() << std::endl;
    std::cout << "Rear element after overflow: " << q.getRear() << std::endl;

    return 0;
}
