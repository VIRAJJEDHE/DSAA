#include<bits/stdc++.h>
using namespace std;

int first(int a[],int n,int i,int x)
{
    if(i==n)
    return -1;
    //cout<<a[i]<<" ";
    if(a[i]==x)
    return i;
    return first(a,n,i+1,x);
}
int last(int a[],int n,int i,int x)
{
    if(i==-1)
    return -1;
    //cout<<a[i]<<" ";
    if(a[i]==x)
    return i;
    return first(a,n,i-1,x);
   
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int x;
    cin>>x;
    cout<<first(a,n,0,x)+1<<" "<<last(a,n,n-1,x)+1;
    return 0;
}