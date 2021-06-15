#include<bits/stdc++.h>
using namespace std;

void subsets(char a[],int n)
{
    for(int i=0;i<=1<<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                cout<<a[j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    int n;
    cin>>n;
    char a[n];
    cin>>a;
    subsets(a,n);
    return 0;
}