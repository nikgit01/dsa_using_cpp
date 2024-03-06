#include "A4_SLL.cpp"

int countList(SLL &s){
    node *t;
    t=s.getFirstNode();
    int count=1;
    while(t->next!=nullptr){
         count++;
         t=t->next;
    }
    return count;    
}
node* middleNode(SLL &s) {
    node *t1, *t2;
    t1 = t2 = s.getFirstNode();
    while (t2 != NULL && t2->next != NULL) {
        t1 = t1->next;
        t2 = t2->next->next;
    }
    return t1;
}
//             Main function
int main()
{
    SLL s1,s2;
    s1.insertAtLast(10);
    s1.insertAtLast(20);
    s1.insertAtLast(30);
    s1.insertAtLast(40);
    s1.insertAtLast(50);
    s1.insertAtLast(70);
    cout<<"S1: "<<countList(s1)<<endl;
    s1.printList();
    // s1.reverseList();
    s1.printList();
    cout<<"middle node is : "<<middleNode(s1)<<endl;
    return 0;
}