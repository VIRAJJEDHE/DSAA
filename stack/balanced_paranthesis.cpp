#include<bits/stdc++.h>
using namespace std;

bool is_balanced(string s)
{
    stack<char> a;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
        {
            a.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(a.empty()==false&&a.top()=='(')
            {
                a.pop();
            }    
            else
            return false;
        }
        else if(s[i]==']')
        {
            if(a.empty()==false&&a.top()=='[')
            {
                a.pop();
            }
            else
            return false;
        }
        else if(s[i]=='}')
        {
            if(a.empty()==false&&a.top()=='{')
            {
                a.pop();
            }
            else
            return false;
        }
    }
    return a.empty();
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    string s="[{()]";
    if(is_balanced(s))
    {
        cout<<"balanced paranthesis";
    }
    else
    cout<<"unbalanced paranthesis";
    return 0;
}