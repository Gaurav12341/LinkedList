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

int search (node* head, int key){
    int pos=1;
    while (head!=NULL)
    {
        if(head->data==key)
            return pos;
        pos++;
        head=head->next;
        }
    return -1;
}

int Rsearch(node* head, int key){
    if(head==NULL)
        return -1;
    if(head->data==key)
        return 1;
    int res= Rsearch(head->next,key);           // returns 1 if element found 
    if(res==-1)
        return -1;
    return res+1;
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    node* head=new node(40);
    head->next=new node(30);
    head->next->next=new node(20);
    head->next->next->next=new node(10);
    cout<<Rsearch(head,20);
}