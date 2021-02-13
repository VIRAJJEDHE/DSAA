#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char a[10];
    cin>>a;
    int high=n-1,low=0,flag=0;
    //cout<<high;
    while(low<=high)
    {
        if(a[low]!=a[high])
        {
            flag=1;
            break;
        }
        low++;
        high--;
    }
    if(flag==0)
    cout<<"this is a palindrome";
    else
    {
        cout<<"this is not a palindrome";
    }
    
}