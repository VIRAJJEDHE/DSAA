#include<bits/stdc++.h>
using namespace std;

 
bool is_Safe(int n,int x,int y,int** arr)
{
    if(x<n&&y<n&&arr[x][y]==1)
    return true;
    return false;

} 
 bool rat_in_Maze(int n,int x,int y,int** arr,int** sol_arr)
{
    if(x==n-1&&y==n-1)
    {
        sol_arr[x][y]=1;
        return true;
    }    
    if(is_Safe(n,x,y,arr))
    {
        sol_arr[x][y]=1;
        if(rat_in_Maze(n,x+1,y,arr,sol_arr))
        return true;
        if(rat_in_Maze(n,x,y+1,arr,sol_arr))
        return true;
        sol_arr[x][y]=0;
        return false;
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
    int **sol_arr;
    arr=new int*[n];
    sol_arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        sol_arr[i]=new int[n];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>arr[i][j];

    }   
    

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
           sol_arr[i][j]=0;
    }

    if(rat_in_Maze(n,0,0,arr,sol_arr))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<sol_arr[i][j]<<" ";
            cout<<endl;
        }        
    }
    else
    cout<<"no possible path";

    for(int i=0;i<n;i++)    //To delete the inner arrays
      delete [] arr[i];   
      delete [] arr;
    for(int i=0;i<n;i++)    //To delete the inner arrays
      delete [] sol_arr[i];   
      delete [] sol_arr;
           

    return 0;
}