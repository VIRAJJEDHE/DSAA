#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[100],b[100];
    cin>>a;
    int current=1,i=0;
    b[0]=a[0];
    while(a[current]!='\0')
    {
        if(a[current]!=b[i])
        {
            i++;
            b[i]=a[current];
        }
        current++;
    }
    for(int j=0;j<=i;j++)
    cout<<b[j];

    return 0;
}