#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};

node* constructBST(int preorder[],int *idx,int key,int max,int min,int n)
{
    if(*idx>=n)
    return NULL;
    node* root=NULL;
    if(key>min&&key<max)
    {
        root=new node(key);
        *idx=*idx+1;
        if(*idx<n)
        {
            root->left=constructBST(preorder,idx,preorder[*idx],key,min,n);
        }
        if(*idx<n)
        {
            root->right=constructBST(preorder,idx,preorder[*idx],max,key,n);
        }
    }
    return root;
}

void inorder(node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    int arr[]={10,2,1,13,11};
    int idx=0;
    node*root=constructBST(arr,&idx,arr[0],INT_MAX,INT_MIN,5);
    //cout<<root->left->data<<" ";
    inorder(root);
    return 0;
}