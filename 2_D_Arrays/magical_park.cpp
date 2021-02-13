#include<bits/stdc++.h>
void magic_park(int m,int n,int a[][n],int k,int s)
{
    bool success=true;
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s<k)
            {
                success=false;
                break;
            }
            if(a[i][j]==".")
            {
                s=s-2;
            }
            else if(a[i][j]=="*")
            {
                s=s+5;
            }
            else{
                break;
            }
            if(j!=n-1)
            s--;
        }
    }
    if(success)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;

}
using namespace std;
int main()
{
    int m,n,k,s,i,j;
    cin>>m>>n>>k>>s;
    int a[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    magic_park(m,n,a,k,s);

    return 0;
}