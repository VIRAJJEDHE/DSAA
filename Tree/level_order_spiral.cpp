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

//vector <int> level_order_spiral(Node *root);
int height(Node* root);
// Function to Build Tree
vector<int> findSpiral(Node* root);
//
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

vector<int> ans;
int main() {
    string s;
    getline(cin, s);
    Node *root=buildTree(s);
    ans.clear();
    ans=findSpiral(root);
    for(auto it: ans)
    {
        cout<<it<<" ";
    }
   return 0;
}

void level_order_spiral(Node *root,int level,bool order)
{
    if(root==NULL)
     return;
     if(level==1)
     ans.push_back(root->data);
     else{
         if(order)
         {
             level_order_spiral(root->left,level-1,order);
             level_order_spiral(root->right,level-1,order);
         }
         else
         {
             level_order_spiral(root->right,level-1,order);
             level_order_spiral(root->left,level-1,order);
         }
     }
   
}
int height(Node *root)
{
    if(root==NULL)
    return 0;
    else
    {
        int lheight=height(root->left);
        int rheight=height(root->right);

        if(lheight>rheight)
        return lheight+1;
        else 
        return rheight+1;
    }
}
vector<int> findSpiral(Node *root)
{
    int h=height(root);
    bool order=0;
    for(int i=1;i<=h;i++)
    {
        level_order_spiral(root,i,order);
        order=!order;
    }

    return ans;
}