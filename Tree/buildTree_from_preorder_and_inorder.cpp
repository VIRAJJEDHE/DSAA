#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int idata)
{
    struct node* node = new struct node;
    node->data = idata;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int search(int arr[],int start,int end,int k)
{
    for(int i=start;i<=end;i++)
    {
        if(arr[i]==k)
        {
            return i;
        }
    }
    return -1;
}
node* buildTree(int pre[],int in[],int start,int end)
{
    static int idx=0;
    int curr=pre[idx];
    idx++;
    int pos=search(in,start,end,curr);
    node* root=newNode(curr);
    if(start==end)
    {
        return root;
    }
    root->left=buildTree(pre,in,start,pos-1);
    root->right=buildTree(pre,in,pos+1,end);
    return root;
}
int main()
{
    int pre[]={1, 2, 4, 5, 3, 6, 7 };
    int in[]={4, 2, 5, 1, 6, 3, 7 };
    node* root;
    root=buildTree(pre,in,0,6);
    cout<<root->left->left->data;
    return 0;
}