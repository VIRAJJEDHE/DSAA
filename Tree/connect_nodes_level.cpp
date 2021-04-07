
//https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1#

#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;
    return temp;
}


void connect(Node* root);
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
    getline(cin, s);
    Node *root=buildTree(s);
    connect(root);
    cout<<root->left->nextRight->data<<" "<<root->left->left->nextRight->data<<" "<<root->left->left->nextRight->nextRight->data<<" "<<root->left->left->nextRight->nextRight->nextRight->data;
    
   return 0;
}

void connect(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* p=q.front();
        q.pop();
        if(p!=NULL)
        {
            p->nextRight=q.front();
            if(p->left!=NULL)
            q.push(p->left);
            if(p->right!=NULL)
            q.push(p->right);

        }
        else if(!q.empty())
            q.push(NULL);
    }

}