#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i=0,j=7;
    int a[]={1,3,6,7,9,12,14,16};
    int k=15;
    while(i<j)
    {
        if(a[i]+a[j]<k)
        i++;
        else if(a[i]+a[j]>k)
        j--;
        else
        {
            cout<<a[i]<<" and "<<a[j]<<endl;
            i++;
            j--;
        }
        
    }
 return 0;
}