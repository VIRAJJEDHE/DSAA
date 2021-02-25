#include<bits/stdc++.h>
using namespace std;

char x;
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
void tree_input(node *root)
{
    if(x=='x')
    return;
    cout<<"Enter x to stop giving input!!"<<endl;
    cout<<"Enter left element of "<<root->data<<" :  ";
    cin>>x;
    if(x!='n')
    {
        root->left=newNode(x-'0');
        tree_input(root->left);
    }
    if(x=='x')
    return;
    cout<<"Enter the right element of "<<root->data<<" :  ";
    cin>>x;
    if(x!='n')
    {
        root->right=newNode(x-'0');
        tree_input(root->right);
    }
    if(x=='x')
    return;
}
void BottomView()
int main()
{
    cout<<"Enter the root Node:";
    cin>>x;
    node *root=newNode( x-'0');
    tree_input(root);
    cout<<root->left->left->right->data;
    return 0;
}