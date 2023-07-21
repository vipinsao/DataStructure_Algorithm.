#include<bits/stdc++.h>
using namespace std;
//Doubly Linked list Implementation completely.
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    //Construtor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    //destructor for deletion completely
    ~Node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for the node whose data is "<<val<<endl;
    }
};
//In my code i am handling the head==NULL cases also.
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
//determining the length of linked list.
int Getlength(Node* head){
    Node* temp = head;
    int size = 0;
    while(temp!=NULL){
        size++;
        temp = temp->next;
    }
    return size;
}
//Inserting at head of linked list.
void InsertionAtHead(Node* &head,int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
    }
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
//Inserting at the last of linkd list
void InsertionAtLast(Node* &head,int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
    }
    Node* temp = new Node(d);
    Node* curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
}
//Inserting at any index in the linked list.
void InsertionAtMiddle(Node* &head,int d,int pos){
    if(pos==1){
        InsertionAtHead(head,d);
        return;
    }
    Node* NodeToInsert = new Node(d);
    Node* curr = head;
    int cnt = 1;
    while(cnt<pos-1){
        curr = curr->next;
        cnt++;
    }
    if(curr->next==NULL){
        InsertionAtLast(head,d);
        return;
    }
    else{
        NodeToInsert->next = curr->next;
        curr->next->prev = NodeToInsert;
        curr->next = NodeToInsert;
        NodeToInsert->prev = curr;
    }
}
//Deletion by Index in the linkd list.
void DeletionAnyIndex(Node* &head,int pos){
    Node* temp = head;
    if(pos==1){
        temp->next->prev = NULL;
        temp->next = NULL;
        head = temp->next;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<=pos-1){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main(){
    Node* head = NULL;
    InsertionAtHead(head,20);
    InsertionAtHead(head,30);
    print(head);
    cout<<endl;
    cout<<Getlength(head)<<endl;
    InsertionAtLast(head,40);
    InsertionAtLast(head,50);
    print(head);
    InsertionAtMiddle(head,60,4);
    print(head);
    DeletionAnyIndex(head,3);
    print(head);
    DeletionAnyIndex(head,5);
    print(head);
    return 0;
}