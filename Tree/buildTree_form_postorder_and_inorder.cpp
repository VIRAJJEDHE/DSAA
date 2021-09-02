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
node* buildTree(int post[],int in[],int start,int end)
{
    static int idx=6;
    int curr=post[idx];
    idx--;
    int pos=search(in,start,end,curr);
    node* root=newNode(curr);
    if(start==end)
    {
        return root;
    }
    root->right=buildTree(post,in,pos+1,end);
    root->left=buildTree(post,in,start,pos-1);
    return root;
}
int main()
{
    int post[]={4,5,2,6,7,3,1};
    int in[]={4,2,5,1,6,3,7};
    node* root;
    root=buildTree(post,in,0,6);
    cout<<root->left->left->data;
    return 0;
}