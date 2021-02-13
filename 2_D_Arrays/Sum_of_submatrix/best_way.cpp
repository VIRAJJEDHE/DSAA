#include<bits/stdc++.h>
using namespace std;
int main()
{   int i,j,x,y,sum=0;
    cin>>y>>x;
    int a[y][x];
    for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        {
            cin>>a[i][j];
            sum+=a[i][j]*((i+1)*(j+1)*(y-i)*(x-j));  
        }
    }
    cout<<sum<<endl;
     
    return 0;
}