#include<iostream>
using namespace std;
class DynArray
{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        DynArray(int);
        bool isEmpty();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        bool isFull();
        int get(int);
        void printArray();
        int count();
        int find(int);
        void sort();
        void duplicatDelete();
        void doubleArray();
        void halfArray();
        int size();
        void del(int);
        ~DynArray();
};
void DynArray::del(int index){
    if(isEmpty())
        cout<<"Array is already full !!\n";
    else if(index<0 || index<lastIndex)
        cout<<"Invalid Index!!\n";
    for(int i=index; i<lastIndex; i++)
        ptr[i]=ptr[i+1];
    lastIndex--;
    if(capacity/2>=lastIndex+1 && capacity>1)
        halfArray();
}
void DynArray::insert(int index, int data){
    int i;
    if(index<0 || index<lastIndex+1)
        cout<<"Invalid Index !!\n";
    else{
        if(isFull())
            doubleArray();
        for(i=lastIndex; i>=index; i--)
            ptr[i+1]=ptr[i];
        ptr[index]=ptr[data];
        lastIndex++;
    }
}
void DynArray::append(int data){
    if(isFull())
        doubleArray();
    lastIndex++;
    ptr[lastIndex]=data;
}
bool DynArray::isEmpty(){
    return lastIndex==-1;
}
int DynArray::size(){
    return capacity;
}
void DynArray::halfArray(){
    int *temp=new int[capacity/2];
    for(int i=0; i<=lastIndex; i++)
        temp[i]=ptr[i];
    delete[]ptr;
    ptr=temp;
    capacity/=2;

}
void DynArray::doubleArray(){
    int *temp = new int[capacity*2];
    for(int i=0; i<=lastIndex; i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;
}
DynArray::DynArray(int cap){
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];
}