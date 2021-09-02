#include<bits/stdc++.h>
using namespace std;

vector<int> stockSpan(vector<int> a)
{
    vector<int> ans;
    stack<pair<int,int>> s;
    for(int i=0;i<a.size();i++)
    {
        int days=1;
        while(!s.empty() and s.top().first<a[i])
        {
            days+=s.top().second;
            s.pop();
        }
        s.push({a[i],days});
        ans.push_back(days);
    }
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    
    vector<int> price={100,80,60,70,60,75,85};
    vector<int> span=stockSpan(price);
    for(auto &it:span)
    {
        cout<<it<<' ';
    }
    return 0;
}