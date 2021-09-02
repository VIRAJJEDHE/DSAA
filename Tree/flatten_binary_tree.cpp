
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
node* LeftEnd(node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
void flatten(node* root)
{
    if(root==NULL);
    return;
    flatten(root->left);  
    node* left_end=LeftEnd(root);
    if(root->right!=NULL)
    left_end->left=root->right;
    root->right=NULL;
    flatten(root->right); 
    return;
}
void print_flattenedTree(node* root)
{
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root=root->left;
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
    print_flattenedTree(root);
    cout<<root->left->right->data;
    //print_flattenedTree(root->left);
    return 0;
}