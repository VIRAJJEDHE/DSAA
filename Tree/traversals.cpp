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
void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* root = q.front();
        q.pop();
        if(root!=NULL)
        {
            cout<<root->data<<" ";
            if(root->left!=NULL)
            {
                q.push(root->left);
            }
            if(root->right!=NULL)
            {
                q.push(root->right);
            }     
        }
        else if(!q.empty())
        q.push(NULL);  
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
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
    return 0;
}