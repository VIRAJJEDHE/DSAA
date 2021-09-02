#include<bits/stdc++.h>
using namespace std;

char x;
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

node* insert_bst(node* root,int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    if(val>root->data)
    {
        root->right=insert_bst(root->right,val);
    }
    else
    {
        root->left=insert_bst(root->left,val);
    }
    return root;
}
node* search_in_bst(node* root,int k)
{
    if(root==NULL)
    return NULL;
    if(root->data==k)
    return root;
    if(root->data<k)
    return search_in_bst(root->left,k);
    return search_in_bst(root->right,k);
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
    node* root;
    int a[]={4,3,5,6,7,2,0,1};
    for(int i=0;i<8;i++)
    {
        insert_bst(root,a[i]);
    }
    inorder(root);
    cout<<endl;
    cout<<search_in_bst(root,3)->data;
    return 0;
}