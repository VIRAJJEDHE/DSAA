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

int sum_at_k(node* root,int k)
{
    if(root==NULL)
    return -1;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int sum=0;
    int level=0;
    while(!q.empty())
    {
        node* root = q.front();
        q.pop();
        if(root!=NULL)
        {
            if(level==k)
            {
                sum+=root->data;
            }
            if(root->left)
            {
                q.push(root->left);
            }
            if(root->right)
            {
                q.push(root->right);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);  
            level++;
        }
        
    }
    return sum;
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
    cout<<sum_at_k(root,2);
    return 0;
}