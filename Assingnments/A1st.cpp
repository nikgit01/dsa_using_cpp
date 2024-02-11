#include<iostream>
using namespace std;
class Array{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int);
        bool isEmpty();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        bool isFull();
        int get(int);
        int count();
        ~Array();
        int find(int);
};
int Array::find(int data)
{
    for(int i=0; i<=lastIndex; i++)
        if(ptr[i]==data)
            return i;
        return -1;
}
Array::~Array()
{
    delete[]ptr;
}
int Array::count()
{
    return lastIndex+1;
}
int Array::get(int index)
{
    if(index>=0 && index<=lastIndex)
        return ptr[index];
    cout<<endl<<"Invalild Index";
        return -1;
}
bool Array::isFull()
{
    return lastIndex==capacity-1;
}
void Array::del(int index)
{
    if(isEmpty())
        cout<<endl<<"Array is empty";
    else if(index<0 || index>lastIndex)
        cout<<endl<<"Invalid Index";
    else{
        for(int i=index; i<lastIndex; i++)
            ptr[i]=ptr[i+1];
            lastIndex--;
    }
}
void Array::edit(int index,int data)
{
    if(index>=0 && index<=lastIndex)
        ptr[index]=data;
}
void Array::insert(int index,int data)
{
    if(lastIndex==capacity-1)
        cout<<endl<<"ERROR Array is already full";
    else if(index<0 || index>lastIndex+1){
        cout<<"Invalid Index";  
    }
    else{
        for(int i=lastIndex; i>=index; i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    }
}
void Array::append(int data)
{
    if(lastIndex==capacity-1)
        cout<<endl<<"ERROR Array is already full";
    else{
        lastIndex++;
        ptr[lastIndex]=data;
    }
}
bool Array::isEmpty()
{
    return lastIndex==-1;
}
Array::Array(int cap)
{
    capacity=cap;
    lastIndex= -1;
    ptr=new int [capacity];
}
int main()
{
    Array obj(5);
    if(obj.isEmpty())
        cout<<"empty array";

    cout<<endl;

    return 0;
}
