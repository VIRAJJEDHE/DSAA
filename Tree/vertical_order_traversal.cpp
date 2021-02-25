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
void VerticalOrderUtil(node* root,map<int,vector<int>> &HdMap,int hd)
{
    if(root==NULL)
    return;
    else
    {
        HdMap[hd].push_back(root->data);
        VerticalOrderUtil(root->left,HdMap,hd-1);
        VerticalOrderUtil(root->right,HdMap,hd+1);
        
    }
}
void VerticalOrder(node* root)
{
    map<int,vector<int>> HdMap;
    int hd=0;
    VerticalOrderUtil(root,HdMap,hd);
     map<int,vector<int>>::iterator itr; 
    cout << "\nThe map vertical order is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = HdMap.begin(); itr != HdMap.end(); ++itr)
    { 
        for(int i=0;i<itr->second.size();i++)
             cout<< '\t' << itr->second[i];
             cout<<endl; 
    }    
}
int main()
{
    cout<<"Enter the root Node:";
    cin>>x;
    node *root=newNode( x-'0');
    tree_input(root);
    VerticalOrder(root);
    return 0;
}