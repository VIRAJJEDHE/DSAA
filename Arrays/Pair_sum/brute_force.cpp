#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=10;
    int a[]={1,3,6,7,9,12,14,16};
    int k=15;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==k)
            cout<<a[i]<<" and "<<a[j]<<endl;
        }
    }
 return 0;
}