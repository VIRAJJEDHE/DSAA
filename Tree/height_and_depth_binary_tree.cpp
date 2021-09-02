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

int height(node* root,int h)
{
    if(root==NULL)
    return h;
    return max(height(root->left,h+1),height(root->right,h+1));
}
int diameter(node* root)
{
    if(root==NULL)
    return 0;
    return max(height(root->right,0)+height(root->left,0)+1,max(diameter(root->right),diameter(root->left)));
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
    cout<<height(root,0)<< " "<<diameter(root);
    return 0;
}