#include<bits/stdc++.h>
using namespace std;

int spiral(int a[][1000],int sr,int er,int sc,int ec)
{
    int i;
    //cout<<"hii function";
    while(sr<=er||sc<=ec)
    {
        //cout<<"hii loop";
        for(i=sc;i<=ec;i++)
        cout<<a[sr][i]<<" ";
        sr++;
        for(i=sr;i<=er;i++)
        cout<<a[i][ec]<<" ";
        ec--;
        if(er>sr){
        for(i=ec;i>=sc;i--)
        cout<<a[er][i]<<" ";
        er--;
        }
        if(ec>sc){
        for(i=er;i>=sr;i--)
        cout<<a[i][sc]<<" ";
        sc++;
        }
        
    }
    return 0;
    
}
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int val=1;
    int a[1000][1000];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            a[i][j]=val;
            val++;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    spiral(a,0,n-1,0,m-1);
    return 0;
    
}