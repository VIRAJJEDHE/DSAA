#include<bits/stdc++.h>
using namespace std;
void rotate_stl(int a[][1000], int n)
{
  for(int i=0;i<n;i++)
  reverse(a[i],a[i]+n);
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          if(j<i)
          swap(a[i][j],a[j][i]);
      }
  }
}
void display(int a[][1000], int n)
{
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             cout<<a[i][j]<<" ";
         }
         cout<<endl;
     }
}
int main()
{
    int n;
    cin>>n;
    int a[1000][1000];
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
	    cin>>a[i][j];
    }
    rotate_stl(a,n);//to rotate anti clockwise
    display(a,n);
}