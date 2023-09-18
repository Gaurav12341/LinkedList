#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* prev;
    node* next;
    node(int x){
        data=x;
        prev=NULL;
        next=NULL;
    }
};

node* insertArBegin(node* head,int x){          //TC: O(1)
    node *temp=new node(x);
    temp->next=head;
    if(head!=NULL)
        head->prev=temp;
    return temp;
}

node* insertAtEnd(node* head, int x){           //TC: O(n)
    node* temp =new node(x);
    if(head==NULL){
        return temp;
    }
    node* curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    temp->prev=head;
    return head;
}

node* insertAtPos(node* head,int pos, int x){           //TC: O(n)
    node* temp=new node(x);
    if(pos==1){
        temp->next=head;
        head->prev=temp;
        return temp;
    }
    node* curr=head;
    for(int index=1; index<=pos-2 && curr!=NULL;index++){
        curr=curr->next;
    }
    node* some=curr->next;
    curr->next=temp;
    temp->next=some;
    return head;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    node* head=new node(10);
    node* temp1= new node(20);
    node* temp2= new node(30);
    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;
    display(head);

    cout<<endl;
    head=insertArBegin(head,5);
    display(head);

    cout<<endl;
    head=insertAtEnd(head,50);
    display(head);

    cout<<endl;
    head=insertAtPos(head,3,70);
    display(head);
    

}