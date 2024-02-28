#include "A1st.cpp"
class ExtentdedArray:public Array
{
    public:
        ExtentdedArray(int);
        int greatest();
};
ExtentdedArray::ExtentdedArray(int cap):Array(cap){cout<<"Object created\n";}
int ExtentdedArray:: greatest(){
    int max;
    if(isEmpty()){
        cout<<"The array was empty";
        return -1;
    }
    max=get(0);
    for(int i=1; i<count(); i++){
        if(max<get(i))
            max=get(i);
    }
    return max;
}
