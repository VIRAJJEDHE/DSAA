#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int r)
{
    int i=l-1;
    int pivot=arr[r];
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[r],arr[i+1]);
    return i+1;
}

void quick_sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int pi=partition(arr,l,r);
        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,r);
    }
    else 
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
    int arr[n];

    for(int i=0;i<n;i++)
    cin>>arr[i];

    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}