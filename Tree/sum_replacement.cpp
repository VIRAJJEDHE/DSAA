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


void sum_replace(node* root)
{
    if(root==NULL)
    return ;
    sum_replace(root->left);
    sum_replace(root->right);
    if(root->left!=NULL)
    root->data+=root->left->data;
    if(root->right!=NULL)
    root->data+=root->right->data;
}

int main()
{
    struct node *root =newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(7 );
    root->left->right = newNode(5);
    sum_replace(root);
    cout<<root->data;
    return 0;
}