#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int item;
    int pno;
    node *next;
};
class PriorityQueue{
    private:
        node *start;
    public:
        PriorityQueue();
        void insert(int,int);
        void del();
        int getElement();
        int getHighestPriorityNo();
        ~PriorityQueue();
        bool isEmpty();
};
bool PriorityQueue::isEmpty()
{
    return start==NULL;
}
PriorityQueue::~PriorityQueue()
{
    while(start)
        del();
}
int PriorityQueue::getHighestPriorityNo()
{
    if(start)
        return start->pno;
    return 0;
}
int PriorityQueue::getElement()
{
    if(start)
        return start->item;
    return -1;
}
void PriorityQueue::del()
{
    node *r;
    if(start)
    {
        r=start;
        start=start->next;
        delete r;
    }
}
void PriorityQueue::insert(int data, int num)
{
    node *t;
    node *n=new node;
    n->item=data;
    n->pno=num;
    if(start==NULL)
    {
        n->next=NULL;
        start=n;
    }
    else
    {
        if(start->pno<n->pno)
        {
            n->next=start;
            start=n;
        }
        else
        {
            t=start;
            while(t->next!=NULL)
            {
                if(t->next->pno >= n->pno)
                    t=t->next;
                else
                    break;
            }
            n->next=t->next;
            t->next=n;
        }
        
    }
}
PriorityQueue::PriorityQueue()
{
    start=NULL;
}

