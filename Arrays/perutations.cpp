#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void permutations(int n,vector<int> &a)
{
    if(n==a.size())
    {
        ans.push_back(a);
        return; 

    }
    
    for(int i=n;i<a.size();i++)
    {
        swap(a[i],a[n]);
        permutations(n+1,a);
        swap(a[i],a[n]);
    }
    return;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &it:a)
    cin>>it;
    
    permutations(0,a);
    //print ans
    for(auto &it:ans)
    {
        for(auto &it2:it)
            cout<<it2<<" ";
        cout<<endl;    
    }

    return 0;
}