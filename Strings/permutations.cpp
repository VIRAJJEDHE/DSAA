#include<bits/stdc++.h>
using namespace std;

void permutations(string a,string ans)
{   
    if(a.length()==0)
    cout<<ans<<" ";
    
    for(int i=0;i<a.length();i++)
    {
        char x=a[i];
        permutations(a.substr(0,i)+a.substr(i+1),ans+x);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    
    string a;
    cin>>a;
    permutations(a,"");
    return 0;
}