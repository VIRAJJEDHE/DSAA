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
node* inorderSuccessor(node* root)
{
    node* ans=root->right;
    while(ans->left!=NULL)
    {
        ans=ans->left;
    }
    return ans;
}
node* delete_in_bst(node* root,int k)
{
    if(root==NULL)
    return root;
    if(root->data<k)
    {
        root->right=delete_in_bst(root->right,k);
    }
    else if(root->data>k)
    {
        root->left=delete_in_bst(root->left,k);
    }
    else
    {
        if(root->left==NULL)
        {
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node* temp=root->left;
            free(root);
            return temp;
        }
        node* temp=inorderSuccessor(root);
        root->data=temp->data;
        root->right=delete_in_bst(root->right,temp->data);
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
    node* root=NULL;
    int a[]={4,3,5,6,7,2,0,1};
    for(int i=0;i<8;i++)
    {
        root=insert_bst(root,a[i]);
    }
    inorder(root);
    cout<<endl;
    cout<<delete_in_bst(root,5)->data;
    cout<<endl;
    inorder(root);
    return 0;
}