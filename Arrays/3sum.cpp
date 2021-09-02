#include<bits/stdc++.h>
using namespace std;

bool TwoSum(vector<int> a,int k,int i)
{
    int j=a.size();
    while(i<j)
    {
        if(a[i]+a[j]<k)
        i++;
        else if(a[i]+a[j]>k)
        j--;
        else
        {
            return true;
        }  
    }
    return false;
}    
bool ThreeSum(vector<int> a,int k)
{
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(TwoSum(a,k-a[i],i))
        return true;
    }
    return false;
}    
int main()
{
    vector<int> a={1,3,6,7,9,12,14,16};
    int k=15;
    sort(a.begin(),a.end());
    cout<<ThreeSum(a,k);
    return 0;
}