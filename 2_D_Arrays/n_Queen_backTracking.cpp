#include<bits/stdc++.h>
using namespace std;

 
bool is_Safe(int n,int x,int y,int** arr)
{
   int row,col;
   for(row=0;row<x;row++)
   {
       if(arr[row][y]==1)
       return false;
   }
   row=x;
   col=y;
   while(row>=0&&col>=0)
   {
       if(arr[row][col]==1)
       {
           return false;
       }
       row--;
       col--;
   }
   row=x;
   col=y;
   while(row>=0&&col<n)
   {
       if(arr[row][col]==1)
       {
           return false;
       }
       row--;
       col++;
   }
   return true;
} 

bool n_queen(int n,int x,int** arr)
{
    if(x>=n)
    {
        return true;
    }    
    for(int i=0;i<n;i++)
    {
        if(is_Safe(n,x,i,arr))
        {
            arr[x][i]=1;
            if(n_queen(n,x+1,arr))
            return true;
            arr[x][i]=0;
        }
    }    
    return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    int n;
    cin>>n;

    int **arr;
    arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    }

    if(n_queen(n,0,arr))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }        
    }
    else
    cout<<"no possible way to add n queens";

    for(int i=0;i<n;i++)    //To delete the inner arrays
      delete [] arr[i];   
      delete [] arr;

    return 0;
}