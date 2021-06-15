
//NOT Complete

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
    return;
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
node* mergeLists(node* &head1,node* &head2)
{
    node* newhead=NULL;
    while(head1!=NULL||head2!=NULL)
    {
        if(head1->data>head2->data)
        {
            insertAtEnd(newhead,head2->data);
            head2=head2->next;
        }
        else{
            insertAtEnd(newhead,head1->data);
            head1=head1->next;
        }
    }
    while(head1!=NULL)
    {
        insertAtEnd(newhead,head1->data);
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        insertAtEnd(newhead,head2->data);
        head2=head2->next;
    }
    display(newhead);
    return newhead;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif     
    int n;
    cin>>n;
    node* head1=NULL;
    node* head2=NULL;
    node* newhead=NULL;
    for(int i=0;i<n;i++)
    {
        int x; 
        cin>>x;
        insertAtEnd(head1,x);
    }
    //display(head1);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x; 
        cin>>x;
        insertAtEnd(head2,x);
    }
    cout<<"here";
    display(head2);
    newhead=mergeLists(head1,head2);
    display(newhead);
   
    return 0;
}