#include<bits/stdc++.h>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s,int x)
{
    if(s.empty()==true)
    {
        s.push(x);
        return;
    }
    int y=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(y);
}
void reverse(stack<int> &s)
{
    if(s.empty())
    return;
    int x=s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,x);

}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverse(s);

    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    //cout<<s.top()<<" ";
    return 0;
}