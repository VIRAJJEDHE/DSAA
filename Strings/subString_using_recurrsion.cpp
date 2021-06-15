#include<bits/stdc++.h>
using namespace std;

void SubStrings(string a,string ans)
{
    if(a.length()==0)
    {
        cout<<ans<<" ";
        return;
    }    
    char ch=a[0];
    SubStrings(a.substr(1),ans);
    SubStrings(a.substr(1),ans+ch);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    
    string a;
    cin>>a;
    SubStrings(a,"");
    return 0;
}