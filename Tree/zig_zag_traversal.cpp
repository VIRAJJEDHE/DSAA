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

void zigzag(node*root)
{
    if(root==NULL)
    return;
    stack<node*> currLevel,nextLevel;
    bool LeftToRight=true;
    currLevel.push(root);
    while(!currLevel.empty())
    {
        node* temp=currLevel.top();
        currLevel.pop();
        if(temp)
        {
            cout<<temp->data<<" ";
            if(LeftToRight)
            {
                if(temp->left)
                nextLevel.push(temp->left);
                if(temp->right)
                nextLevel.push(temp->right);
            }
            else
            {
                 if(temp->right)
                nextLevel.push(temp->right);
                 if(temp->left)
                nextLevel.push(temp->left);
            }
        }
        if(currLevel.empty())
        {
            LeftToRight=!LeftToRight;
            swap(currLevel,nextLevel);
        }
    }
    return;
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
    zigzag(root);
    return 0;
}