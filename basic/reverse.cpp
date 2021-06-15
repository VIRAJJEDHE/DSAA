#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    int a,reverse=0;
    cin>>a;
    while(a!=0)
    {
        reverse=reverse*10+(a%10);
        a=a/10;
    }
    cout<<reverse;
    return 0;
}