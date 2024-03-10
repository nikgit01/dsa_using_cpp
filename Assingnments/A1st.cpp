#include<iostream>
using namespace std;
class Array{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int);
        Array(Array &);
        bool isEmpty();
        void append(int);
        void insert(int,int);
        void edit(int,int);
        void del(int);
        bool isFull();
        int get(int);
        void printArray();
        int count();
            ~Array();
        int find(int);
        // int greatestElement();
        int smallestElement();
        void sort();
        int sumOfAll();
        int avarage();
        void rotate();
        void duplicatDelete();
        int getcapacity();
        void operator=(Array &);
};

void Array::operator=(Array &arr){  // deep copy
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];
}
int Array::getcapacity(){
    return capacity;
}
void Array::duplicatDelete() {
    for(int i = 0; i <= lastIndex; i++) {
        for(int j = i + 1; j <= lastIndex; j++) {
            if(ptr[i] == ptr[j]) {
                for(int k = j; k < lastIndex; k++) {
                    ptr[k] = ptr[k + 1];
                }
                lastIndex--;
                j--; // Decrement j to recheck the current position after removing the duplicate
            }
        }
    }
}
void Array::rotate(){
    int tem=ptr[lastIndex];
    for(int i=lastIndex; i>=0;i--){
        ptr[i]=ptr[i-1];
    }
    ptr[0]=tem;
}
int Array::avarage(){
    return sumOfAll()/count();
}
int Array::sumOfAll(){
    int sum=0;
    for(int i=0; i<=lastIndex; i++)
        sum = sum+ptr[i];

    return sum;
}
void Array::sort() {
    for (int i = 0; i <= lastIndex; i++) {
        for (int j = 0; j < lastIndex - i; j++) {
            if (ptr[j] > ptr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}

int Array::smallestElement(){
    int small=ptr[0];
    for(int i=1; i<=lastIndex;i++){
        if(ptr[i]<small)
            small=ptr[i];
    }
    return small;
}
// int Array::greatestElement(){
//     int big=ptr[0];
//     for(int i=1; i<=lastIndex; i++){
//         if(ptr[i]>big)
//             big=ptr[i];
//     }
//     return big;
// }
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
void Array::printArray(){
    for(int i=0; i<=lastIndex; i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
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
void Array::del(int index) {
    if (isEmpty())
        cout << endl << "Array is empty";
    else if (index < 0 || index > lastIndex)
        cout << endl << "Invalid Index";
    else {
        for (int i = index; i < lastIndex; i++)
            ptr[i] = ptr[i + 1];
        lastIndex--;
        // cout << endl << "Element at index " << index << " deleted.";
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
Array::Array(Array &arr){
    capacity=arr.capacity;
    lastIndex=arr.lastIndex;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
        ptr[i]=arr.ptr[i];
}
Array::Array(int cap)
{
    capacity=cap;
    lastIndex= -1;
    ptr=new int [capacity];
}
/*int main()
{
    Array obj(5);

    cout << endl;
    obj.append(10);
    obj.append(20);
    obj.append(80);
    obj.append(30);
    obj.append(30);
    // obj.insert(2,25);

    // // Print elements before deletion
    // for(int i = 0; i < obj.count(); i++)
    // {
    //     cout << obj.get(i) << " ";
    // }

    // obj.del(3);
    // obj.del(3);
    // cout << endl;

    // // Print elements after deletion
    // for(int i = 0; i < obj.count(); i++)
    // {
    //     cout << obj.get(i) << " ";
    // }
    // cout<<"the greatest elemnet is:"<<obj.greatestElement()<<endl;
    cout<<"The smallest element is:"<<obj.smallestElement()<<endl;
    // obj.sort();
    for(int i = 0; i < obj.count(); i++)
    {
        cout << obj.get(i) << " ";
    }  
    // cout<<endl<<obj.sumOfAll();
    // cout<<endl<<obj.avarage()<<endl; 
    // obj.rotate();
    // obj.rotate();
    cout<<endl;
    obj.duplicatDelete();
    obj.printArray();

    return 0;
} */
