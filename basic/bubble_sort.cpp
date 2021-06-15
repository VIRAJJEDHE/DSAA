#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int n, int arr[])
{
    int temp,counter=1;

    while(counter<n)
    {
        for(int j=0;j<n-counter;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
        counter++;
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

    bubble_sort(n,arr);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}