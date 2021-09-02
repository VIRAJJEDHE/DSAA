
//NOT COMPLETE
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


void printSubtreeNodes(node* root,int k)
{
    if(root==NULL||k<0)
    return;
    if(k==0)
    cout<<root->data<<" ";
    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
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
    printSubtreeNodes(root,2);


    return 0;
}