#include<bits/stdc++.h>
using namespace std;
int main()
{
    //static
    int b[100];
    cout<<sizeof(b)<<endl;

    //Dynamic
    int n;
    cin>>n;
    int *a=new int[n];
    cout<<sizeof(a)<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cout<<a[i]<<" ";
    } 
}