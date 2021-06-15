#include<bits/stdc++.h>
using namespace std;

#define n 10

class stacks
{
    int* arr;
    int top;
    public:
    stacks(){
        int* arr=new int[n];
        top=-1;
    }
    void push(int x)
    {
       if(top==n-1)
       {
           cout<<"Stack Overflow"<<endl;
           return;
       } 
       top++;
       arr[top]=x;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack empty";
            return;
        }
        top--;
    }
    bool empty()
    {
        return top==-1;
    }
    int Top()
    {
        if(top==-1)
        {
            cout<<"Empty stack";
            return -1;
        }
        return arr[top];
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    
    stacks s;
    s.push(1);
    s.push(2);
    cout<<s.Top();
    s.pop();
    cout<<s.Top();
    return 0;
}