#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
   int n,k;
   cin>>n>>k;     
   vector<int> a(n);
   for(auto &it:a)
   {
       cin>>it;
   }
   deque<int> d;
   vector<int> ans;
   for(int i=0;i<k;i++)
   {
       while(!d.empty() and a[d.back()]<a[i])
       {
           d.pop_back();
       }
       d.push_back(i);
   }
    ans.push_back(a[d.front()]);
   for(int i=k;i<n;i++)
   {
       if(d.front()<=i-k)
       {
           d.pop_front();
       }
       while(!d.empty()&&a[d.back()]<a[i])
       {
           d.pop_back();
       }
       d.push_back(i);
       ans.push_back(a[d.front()]);
   } 
   for(auto it:ans)
   {
       cout<<it<<" ";
   }
    
    return 0;
}