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
       int arr[n],start=0,end=0,sum,reqSum; 
       cin>>reqSum;
       for(int i=0;i<n;i++)
       cin>>arr[i];
       sum=arr[0];
       for(int i=0;i<n;i++)
       {
           if(sum==reqSum)
           break;
           else if(sum<reqSum)
           {
               end++;
               sum=sum+arr[end];
           }
           else
           {
               sum=sum-arr[start];
               start++;
           }

       }



        cout<<"Start"<<start<<" "<<"End"<<end<<endl;
        ct++;
    } 
    return 0;
}