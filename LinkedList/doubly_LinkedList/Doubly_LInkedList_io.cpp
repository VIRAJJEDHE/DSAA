#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node*next;
    node* prev;
    
    node(int val=0)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    if(head!=NULL)
    head->prev=n;
    head=n;
}

void insertAtEnd(node* &head,int val)
{
    if(head==NULL)
    {
        insertAtHead(head,val);
    }
    else
    {
        node* n=new node(val);
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;

    }

}
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}

void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    delete todelete;
}
void deleteNode(node* &head,int key)
{
    node* temp=head;
    if(head==NULL)
    {
        cout<<"Doubly Linked List is empty"<<endl;
    }
    if(head->next==NULL)
    {
        if(head->data==key)
        deleteAtHead(head);
        else
        return;
    }
    while(temp->data!=key)
    {
        temp=temp->next;
    }
    node* todelete=temp;
    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;
    delete todelete;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    int n;
    cin>>n;
    node* head=NULL;
    for(int i=0;i<n;i++)
    {
        int x; 
        cin>>x;
        insertAtEnd(head,x);
    }
    insertAtHead(head,0);
    deleteNode(head,3);
    display(head);
    return 0;
}