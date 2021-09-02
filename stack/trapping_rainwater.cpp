#include<bits/stdc++.h>
using namespace std;

int rainwater(vector<int> a)
{
    stack<int> s;
    int n=a.size(),ans=0;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() and a[s.top()]<a[i])
        {
            int h=a[s.top()];
            s.pop();
            if(s.empty())
            {
                break;
            }
            ans+=(i-s.top()-1)*(min(a[s.top()],a[i])-h);
        }
        s.push(i);   
    }
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    
    vector<int> a={3, 0, 2, 0, 4};
    cout<<rainwater(a);
    return 0;
}