
//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


Node* lowest_common(Node* root,int a,int b);
Node* buildTree(string str)
{
    if(str.length() == 0 || str[0] == 'N')
        return NULL;
        
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    string s;
    int a,b;
    getline(cin, s);
    Node *root=buildTree(s);
    cout<<"Enter the two elements to find common ancestor : ";
    cin>>a;
    cin>>b;  
    cout<<"lowest common ancestor is: "<<lowest_common(root,a,b)->data;
   return 0;
}

Node* lowest_common(Node* root,int a,int b)
{
    Node* flag_l=NULL;
    Node* flag_r=NULL;
    if(root==NULL)
    return NULL;
    if(root->data==a||root->data==b)
    {
        return root;
    }
    else
    {
        flag_l=lowest_common(root->left,a,b);
        flag_r=lowest_common(root->right,a,b);
        if(flag_l&&flag_r)
        return root;
    }
    return (flag_l != NULL)? flag_l: flag_r;;

}