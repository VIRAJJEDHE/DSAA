#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row=4,col=4;
    int **arr;
    // creating row heads
    arr= new int* [row];
    // creating 2D  array
    for (int i=0;i<row;i++)
    {
        arr[i]=new int[col]{0};
    }
    // print 2D array
    cout<<"hii";
    for(int i=0;i<row;i++)
    {
        //cout<<"hii";
        for(int j=0;j<col;j++){
        cout<<arr[row][col]<<" ";
        }
        cout<<endl;
        //cout<<"hii";
    }
    delete arr;
   // cout<<"hii";
    return 0;
}