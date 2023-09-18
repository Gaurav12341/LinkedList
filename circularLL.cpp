#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    node(int x){
        data=x;
        next=NULL;
    }
};


node* insertAtBegin(node* head, int x){         //TC: O(n)
    node* temp=new node(x);
    if(head==NULL){
        temp->next=temp;
    }
    else{
        node* curr=head;
        while(curr->next!=head)
            curr=curr->next;
        curr->next=temp;
        temp->next=head;
    }
    return temp;   
}           

node* insertAtBeginEff(node* head, int x){          //TC: O(1)
    node* temp=new node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int val=head->data;
        head->data=temp->data;
        temp->data=val;
        return head;
    }
}

node* insertAtEnd(node*head, int x){
    node*temp =new node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    else{
        node* curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=temp;
        temp->next=head;
        return head;
    }
}

node* insertAtEndEff(node*head, int x){         //TC: O(1)
    node* temp=new node(x);
    if(head==NULL){
        temp->next=temp;
        return temp;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int some=head->data;
        head->data=temp->data;
        temp->data=some;
        return head->next;
    }
}

node* deleteHead(node* head){
    if(head==NULL)
        return NULL;
    else if(head->next==head){
        delete(head);
        return NULL;
    }
    node*curr=head;
    while(curr->next!=head)
        curr=curr->next;
    curr->next=head->next;
    delete(head);
    return curr->next;
}

node* deleteHeadEff(node* head){
    if(head==NULL)
        return NULL;
    else if(head->next==head){
        delete(head);
        return NULL;
    }
    head->data=head->next->data;
    node *temp=head->next;
    head->next=head->next->next;
    delete(temp);
    return head;
}

node* deleteAtPos(node* head, int k){
    if(head==NULL)
        return head;
    if(k==1){
        return head->next;
    }
    node* curr=head;
    for(int i=0;i<k-2;i++)
        curr=curr->next;
    node*temp=curr->next;
    curr->next=curr->next->next;
    delete(temp);
    return head;

}


void printlist(node* head){
    if(head==NULL)return;
    else if(head->next==head){
        cout<<head->data<<" ";
        return;
    }
    else{
        node* temp=head;
        while(temp->next!=head){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data;
    }
}
void printlist2(node* head){
    if(head==NULL) return;
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}

int main(){
    node*head =new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head->next->next->next->next=head;
    printlist2(head);

    cout<<endl;
    head=insertAtBegin(head,5);
    printlist2(head);

    cout<<endl;
    head=insertAtEndEff(head,50);
    printlist2(head);

    cout<<endl;
    head=deleteHeadEff(head);
    printlist2(head);

    cout<<endl;
    head=deleteAtPos(head,2);
    printlist2(head);
}