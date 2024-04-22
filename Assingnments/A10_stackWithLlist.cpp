#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    int item;
    node *next; 
};
class Stack{
    private:
        node *top;
    public:
        Stack();
        Stack(Stack&);
        void push(int);
        bool isEmpty();
        int peek();
        void pop();
        ~Stack();
        void reverseStack();
        bool ispalindrome(int);
        void printStack();
        void operator=(Stack&);
};
void Stack::operator=(Stack &S)
{
    node *t,*n,*p=NULL;
    t=S.top;
    while(t)
    {
        n=new node;
        n->item=t->item;
        if(top==NULL)
            top=n;
        else
            p->next=n;
        t=t->next;
        p=n;
    }
    if(p!=NULL)
        p->next=NULL;
}
void Stack::reverseStack(){
    node *t1,*t2;
    if(top && top->next){
        t2=NULL;
        do{
            t1=top;
            top=top->next;
            t1->next=t2;
            t2=t1;
        }while(top->next!=NULL);
        top->next=t1;
    }
}
Stack::Stack(Stack &S){    // copy constructer of deep copy
    node *t,*n,*p;
    p=NULL;
    t=S.top;
  while(t){
        n=new node();\
        n->item=t->item;
        if(top=NULL)
            top=n;
        else
            p->next=n;
        t=t->next;
        p=n;
    }
    p->next=NULL;
}
Stack::~Stack(){
    while(top)
        pop();
}
void Stack::pop(){
    node *t;  
    if(isEmpty())
        cout<<"\nStack Underflow";
    else{
        t=top;
        top=top->next;
        delete t;
    }
}
int Stack::peek(){
    if(top==NULL){
        cout<<"\nStack is empty ";
        return -1;
    }
    else
        return top->item;
}
bool Stack::isEmpty(){
    return top==NULL;
}
void Stack::push(int data){
    node *n;
    n=new node;
    n->item=data;
    n->next=top; 
    top=n;
}
void reverse(Stack &s1){   //Reversing a stack without makeing member function
    Stack s2;
    while(!s1.isEmpty()){
        s2.push(s1.peek());
        s1.pop();
    }
    s1=s2;
}
Stack::Stack(){
    top=NULL;
}

int len(int x){
    int count=0;
    while(x){
        x/10;
        count++;
    }
    return count;
}
bool Stack::ispalindrome(int x){
    Stack s;
    int l=len(x);
    int i=l/2;
    while(i){
        s.push(x%10);
        x/10;
        i--;
    }
    if(x%2)
        x/10;
    while(x){
        if(x%10==s.peek()){
            s.pop();
            x/10;    
        }
        else
            return false; 
    }
    return true; 
}
void Stack::printStack(){
    reverseStack();
    while(!isEmpty()){
        cout<<" "<<peek();
        pop();
    }
}
int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.printStack();
    return 0;
}