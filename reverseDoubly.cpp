#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
    node(int x){
        data=x;
        next=NULL;
        prev=nullptr;
    }
};

node* insertArBegin(node* head,int x){          //TC: O(1)
    node *temp=new node(x);
    temp->next=head;
    if(head!=NULL)
        head->prev=temp;
    return temp;
}

node* rev(node* head){                  //TC: O(n)
    if(head==NULL ||head->next==NULL)
        return head;
    node* prev=NULL; 
    node* curr=head;
    while(curr!=NULL){
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        curr=curr->prev;
    }
    return prev->prev;
}

node* deleteAtFirst(node* head){            //TC: O(1)
    if(head==NULL)
        return NULL;
    else if(head->next==NULL){
        delete(head);
        return NULL;
    }
    node *curr=head;
    curr=curr->next;
    delete(head);
    curr->prev=NULL;
    return curr;
}

node* deleteAtLast(node* head){             //TC: O(n)
    if(head==NULL)
        return head;
    else if(head->next==NULL){
        delete(head);
        return NULL;
    }
    else{
        node* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next->prev=NULL;
        delete(curr);
        return head;
    }
}

void Rdisplay(node* head){
    if(head==NULL)
        return;
    cout<<head->data<<" ";
    Rdisplay(head->next);
}

int main(){
    node* head= NULL;
    head=insertArBegin(head,10);
    head=insertArBegin(head,20);
    head=insertArBegin(head,30);
    head=insertArBegin(head,40);
    Rdisplay(head);

    cout<<endl;
    head=rev(head);
    Rdisplay(head);

    cout<<endl;
    head=deleteAtFirst(head);
    Rdisplay(head);

    cout<<endl;
    head=deleteAtLast(head);
    Rdisplay(head);
}