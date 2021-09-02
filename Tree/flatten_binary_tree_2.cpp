
//not complete

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
void flatten(node* &root)
{
    if(root==NULL||(root->left==NULL&&root->right==NULL));
    return;
    if(root->left!=NULL)
    {
        flatten(root->left);
        node* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        node* tail=root->right;
        while(tail->right!=NULL)
        tail=tail->right;
        tail->right=temp;
    }
    flatten(root->right);   
    return;
}
void print_flattenedTree(node* root)
{
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->right;
    }
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
    flatten(root);
    //cout<<root->left->left->left->data;
    print_flattenedTree(root);
    return 0;
}