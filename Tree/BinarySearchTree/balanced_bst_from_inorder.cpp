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

node* bst_from_inorder(int inorder[],int low,int high)
{
    if(low>high)
    {
        return NULL;
    }
    int mid=(low+high)/2;
    node*root=newNode(inorder[mid]);
    root->left=bst_from_inorder(inorder,low,mid-1);
    root->right=bst_from_inorder(inorder,mid+1,high);
    return root;
} 
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    node* root=bst_from_inorder(arr,0,6);
    inorder(root);
    cout<<endl;
    preorder(root);
    return 0;
}