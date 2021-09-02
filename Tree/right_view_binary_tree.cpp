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

/*void right_view_util(node* root,int h,int level)
{
    if(root==NULL)
    {
        return;
    }
    if(level==h)
    {
        cout<<root->data<<" ";
        level++;
    }
    right_view_util(root->right,h+1,level);
    right_view_util(root->left,h+1,level);
}
void right_view(node* root)
{
    right_view_util(root,0,0);
}
*/
void right_view(node* root)
{
    if(root==NULL)
    return;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            node* curr=q.front();
            q.pop();
            if(i==n-1)
            cout<<curr->data<<" ";
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
        }
    }
}
void left_view(node* root)
{
    if(root==NULL)
    return;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            node* curr=q.front();
            q.pop();
            if(i==0)
            cout<<curr->data<<" ";
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
        }
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
    right_view(root);
    cout<<endl;
    left_view(root);
    return 0;
}