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

node* LCA(node* root,int n1,int n2)
{
    if(root==NULL)
    return NULL;
    if(root->data==n1||root->data==n2)
    return root;
    node*left=LCA(root->left,n1,n2);
    node*right=LCA(root->right,n1,n2);
    if(left&&right)
    return root;
    return left?left:right;
}
int height(node* root,int k,int h)
{
    if(root==NULL)
    return -1;
    if(root->data==k)
    return h;
    return max(height(root->left,k,h+1),height(root->right,k,h+1));
}
int shortest_dist(node*root, int n1,int n2)
{
    int ans;
    node*lca=LCA(root,n1,n2);
    int h1=height(lca,n1,0);
    int h2=height(lca,n2,0);
    return h1+h2;
}
int main()
{
    struct node *root =newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->right = newNode(5);
    cout<<LCA(root,4,5)->data<<" ";
    cout<<shortest_dist(root,4,3);
    return 0;
}