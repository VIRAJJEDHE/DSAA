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
int main()
{
    struct node *root =newNode(8);
    root->left = newNode(4);
    root->right = newNode(3);
    root->left->left = newNode(7);
    cout<<root->left->left->data;
    return 0;
}