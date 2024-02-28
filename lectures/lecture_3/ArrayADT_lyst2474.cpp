#include<iostream>
using namespace std;
class Array
{
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
        int find(int);
        ~Array();

};
int Array::find(int data)
{
    int i;
    for(i=0;i<=lastIndex;i++)
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
    cout<<endl<<"Invalid index or empty array";
    return -1;
}
bool Array::isFull()
{
    return lastIndex==capacity-1;
}
void Array::del(int index)
{
    int i;
    if(isEmpty())
        cout<<endl<<"Array is empty";
    else if(index<0 || index>lastIndex)
        cout<<endl<<"Invalid Index";
    else
    {
        for(i=index;i<lastIndex;i++)
            ptr[i]=ptr[i+1];
        lastIndex--;
    }
    
}
void Array::edit(int index,int data)
{
    if(index>=0&&index<=lastIndex)
        ptr[index]=data;
}
void Array::insert(int index,int data)
{
    int i;
    if(lastIndex==capacity-1)
        cout<<endl<<"Array is already full";
    else if(index<0 || index>lastIndex+1)
    {
        cout<<"Invalid Index";
    }
    else
    {
        for(i=lastIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=data;
        lastIndex++;
    }
}
void Array::append(int data)
{
    if(lastIndex==capacity-1)
        cout<<endl<<"Array is already full";
    else
    {
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
    lastIndex=-1;
    ptr=new int[capacity];

}
int main()
{
    Array obj(5);
    if(obj.isEmpty())
        cout<<"Empty Array";
    obj.append(20);
    obj.append(40);
    obj.append(60);
    obj.insert(1,30);

    for(int i=0;i<obj.count();i++)
        cout<<obj.get(i)<<" ";
    obj.del(2);
    cout<<endl;
    for(int i=0;i<obj.count();i++)
        cout<<obj.get(i)<<" ";
    
    cout<<endl;
    return 0;
}