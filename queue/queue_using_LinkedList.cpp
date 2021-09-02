#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
class queuee
{
    node* front;
    node* back;
    public:
    queuee()
    {
        front=NULL;
        back=NULL;
    }
    void push(int x)
    {
        node* n=new node(x);
        if(front==NULL)
        {
            front=n;
            back=n;
            return;
        }
        back->next=n;
        back=n;
    }
    void pop()
    {
        if(front==NULL)
        {
            cout<<"Empty Queue"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;
        delete todelete;
    }

    int peek()
    {
        if(front==NULL)
        {
            cout<<"Queue empty";
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        return front==NULL;
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    queuee a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    cout<<a.empty();
    cout<<a.peek()<<" ";
    a.pop();
    cout<<a.peek()<<" ";
    a.pop();
    cout<<a.peek()<<" ";
    a.pop();
    cout<<a.peek()<<" ";
    a.pop();
    cout<<a.peek()<<" ";
    a.pop();
    cout<<a.empty();

    
    return 0;
}