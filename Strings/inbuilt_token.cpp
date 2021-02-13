#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[]="coding, is fun, only if, the compiler works correctly";
    char* t;
    t=strtok(a,",");
    cout<<t<<endl;
    while(t!=NULL)
    {
        t=strtok(NULL,",");
        cout<<t<<endl;
    }
    
}