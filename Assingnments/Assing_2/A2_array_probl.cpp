#include<iostream>
#include "A1st.cpp"
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
        int search(int);
        int sumOfAll();
        int count();
        int avarage();
        void rotate();
        void duplicatDelete();
};
void Array::duplicatDelete(){   // code again q
    for(int i=0; i<lastIndex-1; i++){
        for(int j=i+1; j<=lastIndex; j++){
            if(ptr[i]=ptr[j]){
                for(int k=j; k<lastIndex; k++)
                    ptr[k]=ptr[k+1];
                lastIndex--;
            }
        }
    }
}
void Array::rotate(){
    int tem=lastIndex;
    for(int i=lastIndex; i>=0;i--){
        ptr[i]=ptr[i-1];
    }
}
int Array::avarage(){
    return sumOfAll()/count();
}
int Array::count(){
    return lastIndex+1;
}
int Array::sumOfAll(){
    int sum=0;
    for(int i=0; i<=lastIndex; i++)
        sum = sum+ptr[i];

    return sum;
}
int Array::search(int element) {
    for (int i = 0; i <= lastIndex; i++) {
        if (ptr[i] == element) {
            return i; // Return the index of the element if found
        }
    }
    return -1; // Return -1 if the element is not found
}

int Array::smallestElement(){    //Question 3
    int small=ptr[0];
    for(int i=1; i<=lastIndex;i++){
        if(ptr[i]<small)
            small=ptr[i];
    }
    return small;
}
int Array::greatestElement(){    //Question 2
    int big=ptr[0];
    for(int i=1; i<=lastIndex; i++){
        if(ptr[i]>big)
            big=ptr[i];
    }
    return big;
}
void Array::sort() {             // question 1
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
