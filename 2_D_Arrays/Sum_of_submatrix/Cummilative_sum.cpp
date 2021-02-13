#include<bits/stdc++.h>
using namespace std;
int main()
{   int i,j,tlx,tly,brx,bry,x,y,sum=0;
    cin>>y>>x;
    int a[y][x],b[x][y],cummilative_sum=0;
    for(i=0;i<y;i++)
    {
        cummilative_sum=0;
        for(j=0;j<x;j++)
        {
            cin>>a[i][j];
            cummilative_sum+=a[i][j];
            b[i][j]=cummilative_sum;
        }
        
    }
    for(j=0;j<x;j++)
    {
        cummilative_sum=0;
        for(i=0;i<y;i++)
        {
            cummilative_sum+=a[i][j];
            b[i][j]=cummilative_sum;
        }
        
    }
    for(tly=0;tly<y;tly++)
    {
        for(tlx=0;tlx<x;tlx++)
        {
            for(bry=tly;bry<y;bry++)
            {
                for(brx=tlx;brx<x;brx++)
                {
                    sum+=b[bry][brx]-b[tly][tlx]+a[tly][tlx];
                    if(tly>0)
                    sum=sum-b[tly-1][brx];
                    if(tlx>0)
                    sum-=b[bry][tlx-1];
                }
            }
        }
    }
    cout<<sum<<endl;
     
    return 0;
}