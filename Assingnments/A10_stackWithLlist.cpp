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
        void push(int);
        bool isEmpty();
        int peek();
        void pop();
        ~Stack();
        void reverseStack();
        bool ispalindrome(int);
};
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
Stack::~Stack(){
    while(top!=NULL)
        pop();
}
void Stack::pop(){
    node *t;  
    if(top==NULL){
        cout<<"\nStack Underflow";
    }
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
    Stack s1;
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
            s.pop;
            x/10;    
        }
        else
            return false; 
    }
    return true; 
}