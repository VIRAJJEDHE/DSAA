#include<bits/stdc++.h>
using namespace std;
int main()
{   int i,j,tlx,tly,brx,bry,x,y,sum=0;
    cin>>y>>x;
    int a[y][x];
    for(i=0;i<y;i++)
    {
        for(j=0;j<x;j++)
        cin>>a[i][j];
    }
    
    for(tly=0;tly<y;tly++)
    {
        for(tlx=0;tlx<x;tlx++)
        {
            for(bry=tly;bry<y;bry++)
            {
                for(brx=tlx;brx<x;brx++)
                {
                    for(i=tly;i<=bry;i++)
                    {
                        for(j=tlx;j<=brx;j++)
                        sum=sum+a[i][j];
                    }
                }
            }
        }
    }
    cout<<sum<<endl;

    return 0;
}