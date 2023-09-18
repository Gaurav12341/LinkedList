#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
    node(int x){
        data=x;
        next=NULL;
    }
};

node* insertAtBegin(node* head,int x){      //TC: O(1)
    node* temp=new node(x);
    temp->next=head;
    return temp;            //new head
}

node* insertAtEnd(node *head, int x){          //TC: O(n)
    node* temp=new node(x);
    node* curr=head;
    if(head==NULL)                  //to check if this is the first element in the list  i.e head is nulll so new head should be this new element
        return temp;                    //head changes as only 1 element
    while (curr->next!=NULL)  
    {
        /* code */
        curr=curr->next;
    }
    curr->next=temp;
    return head;   
}

node* insertAtPos(node* head, int pos, int x){              //TC: O(n)
    node* temp=new node(x);
    if(pos==1){                 //1st element
        temp->next=head;
        return temp;                //new head
    }
    node* curr=head;
    for(int i=1;i<=pos-2 && curr!=NULL;i++)         
        curr=curr->next;
    if (curr==NULL)     //the position is out of reach
        return head;        // no element added
    
    temp->next=curr->next;
    curr->next=temp;
    return head;
}


node* sortedinsert(node*head, int x){
    node* temp= new node(x);
    if(head==NULL)
        return temp;
    else if(x<head->data)
        {
            temp->next=head;
            return temp;
        }
    node* curr=head;
    while(curr->next!=NULL && curr->next->data<x)
        curr=curr->next;
    temp->next=curr->next;
    curr->next=temp;
    return head;   
}

int middleLinkedList(node* head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}

int nthNodeFromEnd(node* head, int n){
    node*curr= head;
    int len=0;
    while(curr!=NULL){
        len++;
        curr=curr->next;
    }
    node *temp=head;
    for(int i=1;i<len-n+1;i++)
        temp=temp->next;
    return temp->data;
}

int nthNodeFromEndEff(node* head, int n){
    node*first= head;
    node*second=head;
    while(n--){
        if(first==NULL) return -1;
        first=first->next;
    }
    while(first!=NULL){
        first=first->next;
        second= second->next;
    }
    return second->data;
}

node* deleteAtbegin(node* head){        //TC: O(1)
    if(head==NULL)
        return head;
    node* temp=head->next;
    delete(head);
    return temp; 
}

node* deleteAtEnd(node* head){          //TC: O(n)
    if(head==NULL)
        return head;
    else if(head->next==NULL){
        delete(head);
        return NULL;
    }
    node* curr=head;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    delete(curr->next);
    curr->next=NULL;
    return head;
}

node* deleteAtPos(node* head,int pos){          //TC: o(n)
    int index=1;
    node*curr=head;
    if(index==pos){
        head=head->next;
        delete(curr);
        return head;
    }
    for(index;index<=pos-2 && curr!=NULL;index++){
        curr=curr->next;
    }
    node* temp=curr->next;
    curr->next=temp->next;
    delete(temp);
    return head;

}

node* reversedLL(node* head){       //TC: O(n)
    node* curr=head;
    node* prev=NULL;
    while(curr!=NULL){
        node*next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

node* reverseInGroups(node* head, int k){       //O(n/k)
    node*curr=head;
    node*prev=NULL;
    node* next=NULL;
    int count=0;
    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
        node* resthead=reverseInGroups(next,k);
        head->next=resthead;
    }
    return prev;
}

bool isLoop(node* head){
    node*curr=head;
    node* temp= new node(0);
    while (curr!=NULL){
        if(curr->next==NULL)
            return false;
        if(curr->next==temp)
            return true;
        node* c_next=curr->next;
        curr->next=temp;
        curr=c_next;
    }
    return false;
}

bool isLoopUsingMap(node* head){
    unordered_set<node* >s;
    node* curr=head;
    while(curr!=NULL){
        if(s.find(curr)!=s.end())           //node  already present
            return true;
        s.insert(curr);
        curr=curr->next;
    }
    return false;
}

bool isLoopFloyd(node* head){               //TC: O(n) 
    node* slow=head, *fast=head;                //when the distance between fast and slow becomes the length of the loop they are at the same point
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}

node* loopStart(node* head){
    node* slow=head, *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(slow==fast)
            slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    return NULL;
}

void deleteLoop(node* head){
    node*slow=head, *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }
    if(slow!=fast)
        return;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
}

node* EvenOdd(node* head){              //Tc: O(n)
    node* curr=head;
    node* es=NULL, *ee=NULL, *os=NULL, *oe=NULL;
    while(curr!=NULL){
        if (curr->data%2==0){
            if(es==NULL){
                es=ee=curr;
            }
            else{
                ee->next=curr;
                ee=ee->next;
            }
        }
        else{
            if(os==NULL)
                os=oe=curr;
            else{
                oe->next=curr;
                oe=oe->next;
            }
        }
        curr=curr->next;
    }
    if(os==NULL || es==NULL)
        return head;
    ee->next=os;
    oe->next=NULL;
    return es;
}

int intersection(node* head1, node* head2){         //TC: O(m+n)
    unordered_set<node* >s;
    node* curr=head1;
    while(curr!=NULL){
        if(s.find(curr)==s.end())
            s.insert(curr);
        curr=curr->next;
    }
    curr=head2;
    while(curr!=NULL){
        if(s.find(curr)!=s.end())
            return curr->data;
        curr=curr->next;
    }
    return -1;
}

int getcount(node*head){
    int count=0;
    node* curr=head;
    while(curr!=NULL){
        count++;
        curr=curr->next;
    }
}

int getIntersection(node* head1,node*head2, int d){
    node* curr1=head1, *curr2=head2;
    for(int i=0;i<d;i++){
        if(curr1==NULL)
            return -1;
        curr1=curr1->next;
    }
    while(curr1!=NULL && curr2!=NULL){
        if(curr1==curr2)
            return curr1->data;
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return -1;
}

int optimisedIntersection( node* head1, node* head2){
    int c1=getcount(head1), c2=getcount(head2);
    int diff=abs(c1-c2);
    if(c1>c2){
        return getIntersection(head1, head2, diff);
    }
    else
        return getIntersection(head2,head1,diff);   
}

node* mergeLL(node *head1, node* head2){
    if(head1==NULL)
        return head2;
    else if(head2==NULL)
        return head1;
    node* head=NULL,*tail=NULL;
    if(head1->data<=head2->data){
        head=tail=head1;
        head1=head1->next;
    }
    else{
        head=tail=head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            tail->next=head1;
            tail=head1;
            head1=head->next;
        }
        else{
            tail->next=head2;
            tail=head2;
            head2=head2->next;
        }
    if(head1==NULL)
        tail->next=head2;
    else
        tail->next=head1;
    }
    return head;
}
void removeDup(node* head){
    
    node* curr=head;
    if(curr==NULL)
        return;
    while(curr->next!=NULL ){
        if(curr->data==curr->next->data){
            node* temp=curr->next;
            curr->next=curr->next->next;
            delete(temp);
        }
        else
            curr=curr->next;
    }
}

void Rdisplay(node* head){
    if(head==NULL)
        return;
    cout<<head->data<<" ";
    Rdisplay(head->next);
}

int main(){
    node* head=NULL;
    head=insertAtBegin(head,30);
    head=insertAtBegin(head,10);
    head=insertAtBegin(head,10);
    head=insertAtBegin(head,5);
    Rdisplay(head);

    // head=insertAtEnd(head,50);
    // cout<<endl;
    // Rdisplay(head);

    // cout<<endl;
    // head=insertAtPos(head,2,77);
    // Rdisplay(head);

    // cout<<endl;
    // head=deleteAtbegin(head);
    // Rdisplay(head);

    // cout<<endl;
    // head=deleteAtEnd(head);
    // Rdisplay(head);

    cout<<endl;
    head=deleteAtPos(head,2);
    Rdisplay(head);

    cout<<endl;
    head=sortedinsert(head,1);
    Rdisplay(head);

    cout<<endl;
    int m=middleLinkedList(head);
    cout<<"Middle Element: "<<m;
    
    cout<<endl;
    int n=nthNodeFromEnd(head,3);
    cout<<"Nth Element from end: "<<n;

    cout<<endl;
    int n2=nthNodeFromEndEff(head,3);
    cout<<"Nth Element from end: "<<n2;

    cout<<endl;
    removeDup(head);
    Rdisplay(head);

    cout<<endl;
    head=EvenOdd(head);
    Rdisplay(head);
    
}