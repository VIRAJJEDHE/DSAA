#include<bits/stdc++.h>
using namespace std;

int largest_rectangle(vector<int> a)
{
    stack<int> s;
    a.push_back(0);
    int n=a.size(),i=0,area,maxArea=-1;
    while(i<n)
    {
        if(s.empty()||a[s.top()]<a[i])
            s.push(i);
        else
        {
            while(!s.empty() and a[s.top()]>a[i])
            {
                int h=a[s.top()];
                s.pop();
                if(s.empty())
                {
                    area=h*i;
                }
                else
                {
                    area=h*(i-s.top()-1);
                }
                 maxArea=max(maxArea,area);
            }
            s.push(i);
        }
        
        i++;
    }
    return maxArea;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    
    vector<int> a={1,2,4};
    cout<<largest_rectangle(a);
    return 0;
}