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
        void sort();
        int greatestElement();
        int smallestElement();
};
int Array::smallestElement(){
    int small=ptr[0];
    for(int i=1; i<=lastIndex;i++){
        if(ptr[i]<small)
            small=ptr[i];
    }
    return small;
}
int Array::greatestElement(){
    int big=ptr[0];
    for(int i=1; i<=lastIndex; i++){
        if(ptr[i]>big)
            big=ptr[i];
    }
    return big;
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

Array::Array(int cap)
{
    capacity=cap;
    lastIndex=-1;
    ptr=new int[capacity];
}
