#include<bits/stdc++.h>
using namespace std;
int main()
{
     int a[]={-1,-2,3,6,-4,5,7,8,-2,4};
     int n=10,csum=0,max_sum=0;
     for(int i=0;i<n;i++)
     {
         csum=csum+a[i];
         if(csum<0)
         csum=0;
         if(csum>max_sum)
         max_sum=csum;
     }
     cout<<max_sum;
     return 0;
}