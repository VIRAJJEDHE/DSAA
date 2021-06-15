#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int n, int arr[])
{
    int current;

    for(int i=1;i<n;i++)
    {
        current=arr[i];
        int j=i-1;
        while(arr[j]>current&&j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
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
    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    insertion_sort(n,arr);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}