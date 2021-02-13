#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]={-1,-2,3,6,-4,5,7,8,-2,4};
    int n=10,csum=0,max_sum=0;
    for(int i=0;i<n;i++)
    {   
        for(int j=i;j<n;j++)
        {
            csum=0;
            for(int k=i;k<=j;k++)
            {
                csum=csum+a[k];
            }
            if(csum>max_sum)
            max_sum=csum;    
        }
    }
    cout<<max_sum;

    return 0;
}