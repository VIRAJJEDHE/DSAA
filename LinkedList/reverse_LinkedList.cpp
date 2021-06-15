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
    cout<<endl;
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

node* reverse_iterative(node* &head)
{
    node* previous=NULL,*current=head,*nextptr;
    while(current!=NULL)
    {
        nextptr=current->next;
        current->next=previous;
        previous=current;
        current=nextptr;
    }
    return previous;
}
node* reverse_recurrsive(node* &head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node* new_head=reverse_recurrsive(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_head;
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
    head=reverse_iterative(head);
    display(head);
    head=reverse_recurrsive(head);
    display(head);
    return 0;
}