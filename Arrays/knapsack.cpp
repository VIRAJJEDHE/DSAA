#include<bits/stdc++.h>
using namespace std;

int knapsack(int n,int v[],int w[],int W)
{
    if(n==0||W==0)
    return 0;

    if(w[n-1]>W)
    return knapsack(n-1,v,w,W);

    return max(knapsack(n-1,v,w,W-w[n-1])+v[n-1],knapsack(n-1,v,w,W));
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    int n,W;
    cin>>n>>W;
    int v[n],w[n];
    for(int i=0;i<n;i++)
    cin>>v[i]>>w[i];
    cout<<knapsack(n,v,w,W);
    return 0;
}