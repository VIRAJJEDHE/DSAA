// Question Link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
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
void BottomViewUtil(node* root,map<int,pair<int,int>> &HdMap,int hd,int vd)
{
    if(root==NULL)
    return;
        if(vd>HdMap[hd].second)    
        {
            HdMap[hd]={root->data,vd};
        }    
        BottomViewUtil(root->left,HdMap,hd-1,vd+1);
        BottomViewUtil(root->right,HdMap,hd+1,vd+1);
}
void BottomView(node* root)
{
    map<int,pair<int,int>> HdMap;
    int hd=0;
    BottomViewUtil(root,HdMap,hd,0);
     map<int,pair<int,int>>::iterator itr; 
    cout << "\nThe map vertical order traversal is : "; 
    for (auto itr: HdMap)
    { 
        cout<<itr.second.first<<" ";
    }    
}
int main()
{
    cout<<"Enter the root Node:";
    cin>>x;
    node *root=newNode( x-'0');
    tree_input(root);
    BottomView(root);
    return 0;
}