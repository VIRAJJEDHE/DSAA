#include<bits/stdc++.h>
using namespace std;

void reverse(string a)
{
    if(a.length()==0)
    return;
    reverse(a.substr(1));
    cout<<a[0];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    
    string a;
    cin>>a;
    reverse(a);
    return 0;
}