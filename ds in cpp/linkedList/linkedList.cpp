#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printList(Node *head){
    // Node *curr=head;
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

void RPrint(Node *head){
    if(head==NULL) return;
    cout<<head->data<<" ";
    RPrint(head->next);
}

Node *insB(Node *head, int x){
    Node *temp=new Node(x);
    if(!head) return temp;
    temp->next=head;
    return temp;
}

Node *insE(Node *head, int x){
    Node *temp=new Node(x);
    if(!head) return temp; //edge case
    Node *curr = head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}

Node *delHead(Node *head){
    if(!head) return NULL;
    // else return head->next;
    Node *temp=head->next;
    delete head; //we need to deallocate memory too in cpp.
    return temp;
}

Node *delTail(Node *head){
    if(!head) return NULL;
    if(!(head->next)){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    delete curr->next;
    curr->next=NULL;
    return head;
}

Node *insPos(Node *head, int pos, int x){
    if(!head) return NULL;
    Node *temp=new Node(x);
    if(pos==1){
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    for(int i=1; i<=pos-2 and curr!=NULL; i++){
        curr=curr->next;
    }
    if(!curr) return head; //pos is out of reach
    temp->next=curr->next;
    curr->next=temp;
    // int count=1;
    // Node *curr, *prev=head;
    // while(curr){
    //     if(count==pos){
    //         temp->next=prev->next;
    //         prev->next=temp;
    //         return head;
    //     }
    //     count++;
    //     prev=curr;
    //     curr=curr->next;
    // }
    return head;
}

int search(Node *head, int x){
    int pos=1;
    Node *curr=head;
    while(curr){
        if(curr->data==x) return pos;
        else {
            pos++;
            curr=curr->next;
        }
    }
    return -1;
}

int Rsearch(Node *head, int x){
    if(head==NULL) return -1;
    if(head->data==x) return 1;
    else{
        int res=Rsearch(head->next,x);
        if(res==-1) return -1;
        return res+1;
    }
}

int main(){
    Node *head=new Node(5);
    head->next=new Node(10);
    head->next->next=new Node(15);
    Node *temp1=head->next->next->next=new Node(20);
    temp1->next=new Node(25);
    // head = insB(head,30);
    // head = insE(head,40);
    // head = delHead(head);
    // head = delTail(head);
    RPrint(head); cout<<endl;

    // head = insPos(head,5,8);
    // cout<<search(head,5)<<endl;
    // cout<<Rsearch(head,5)<<endl;

    // printList(head); cout<<endl;
    RPrint(head);
return 0;
}