#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={-1,-2,3,6,-4,5,7,8,-2,4};
    int n=10,csum=0,max_sum=0;
    int cumilative_a[10];
    cumilative_a[0]=a[0];
    for(int i=1;i<n;i++)
        cumilative_a[i]=cumilative_a[i-1]+a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            csum=cumilative_a[j]-cumilative_a[i];
        }
        if(csum>max_sum)
        {
            max_sum=csum;
        }
    }
    cout<<max_sum;
    return 0;    
}