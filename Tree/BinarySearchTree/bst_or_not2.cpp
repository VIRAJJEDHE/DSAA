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

bool isBST(node* root,int max,int min)
{
    if(root==NULL)
    return true;
    if(root->data>=max||root->data<=min)
    return false;
    //if(isBST(root->left,root->data,min)&&isBST(root->right,max,root->data))
    return (isBST(root->left,root->data,min)&&isBST(root->right,max,root->data));
}

int main()
{
    struct node *root =newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
    root->left->right = newNode(3);
    cout<<isBST(root,INT_MAX,INT_MIN);
    return 0;
}