#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif 

    int t,ct=1;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       int arr[n],diff,count=2,Max=0; 
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
           if(i==1)
           diff=arr[1]-arr[0];
           if(i>1)
           {
               if(arr[i]-arr[i-1]==diff)
               count++;
               else
               {
                   Max=max(count,Max);
                   count=2;
                   diff=arr[i]-arr[i-1];
               }
           }
       }   
        Max=max(count,Max);
        cout<<"Case#"<<ct<<":"<<Max<<endl;
        ct++;
    } 
    return 0;
}