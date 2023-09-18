#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;         //self referencial structure
    Node(int x){
        data=x;
        next=NULL;
    }
};

void displaylist (Node *head){
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

void recursiveDisplay (Node* head){
    if(head==NULL)
        return;
    cout<<head->data<<" ";
    recursiveDisplay(head->next);
}

int main(){
    Node *head=new Node(10);
    // Node *temp1=new Node(20);
    // Node *temp2=new Node(30);

    // head->next=temp1;
    // temp1->next=temp2;
    head->next=new Node(20);
    head->next->next=new Node(30);
    displaylist(head);
    cout<<endl;
    recursiveDisplay(head);
    return 0;

}
