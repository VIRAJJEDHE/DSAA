


// NOT COMPLETE

#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node*next;
    
    node(int val=0)
    {
        data=val;
        next=NULL;
    }
};

void insertAtEnd(node* &head,int val)
{
    node* n=new node(val);
    node* temp=head;
    if(head==NULL)
    {
        head=n;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;

}
void insertAtHead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
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
        cout<<"Linked List is empty"<<endl;
    }
    if(head->next==NULL)
    {
        if(head->data==key)
        deleteAtHead(head);
        else
        return;
    }
    while(temp->next->data!=key)
    {
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

bool detect_cycle(node* &head)
{
    node* fast=head,*slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}
void make_cycle(node* head,int pos)
{
    node*temp=head;
    node* cyclepoint;
    int count=1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            cyclepoint=temp;
        }
        count++;
        temp=temp->next;
    }
    temp->next=cyclepoint;
}
void remove_cycle(node* head)
{
    node* fast=head,*slow=head;
    slow=slow->next;
    fast=fast->next->next;
    while(fast!=slow)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"cycle detected";
    fast=head;
    while(fast->next==slow->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    cout<<"cycle removed";
    slow->next=NULL;
    return;
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
    make_cycle(head,2);
    cout<<detect_cycle(head)<<endl;
    remove_cycle(head);
    cout<<detect_cycle(head)<<endl;
    display(head);
    return 0;
}