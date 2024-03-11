#include<iostream>
#include "A1st.cpp"
using namespace std;
class Stack : private Array
{
    public:
        Stack(int);
        void push(int);
        int peek();
        void pop();
        ~Stack();
        virtual bool isFull();
        virtual bool isEmpty();
        Stack(Stack &);
        int getStackSize();
        void operator=(Stack &);
};
void Stack::operator=(Stack &s){ // operator overloading
    Array::operator=(s);
}
int Stack::getStackSize(){
    return getcapacity();
}
Stack::Stack(Stack &S):Array(S)
{}
bool Stack::isEmpty(){
    return Array::isEmpty();
}
bool Stack::isFull(){
    return Array::isFull();
}
Stack::~Stack() {}
void Stack::pop(){
    if(isEmpty())
        cout<<"Stack Underflow\n";
    else
        del(count()-1);
}
int Stack::peek(){
    if(!isEmpty())
        return get(count()-1);
    else
        cout<<"Stack is empty";
    return 0;
}
void Stack::push(int data){
    if(isFull())
        cout<<"Stack OverFlow\n";
    else
        append(data);
}
Stack::Stack(int cap):Array(cap){ }

void reverseStack(Stack &s1){
    Stack s2(s1.getStackSize());

    while(!s1.isEmpty()){
        s2.push(s1.peek());
        s1.pop();
    }
    s1=s2;
}

int main()
{
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<"last element of stack is : "<<s.peek()<<endl;
    reverseStack(s);
    cout<<"last element of stack is : "<<s.peek()<<endl;
    return 0;
}
