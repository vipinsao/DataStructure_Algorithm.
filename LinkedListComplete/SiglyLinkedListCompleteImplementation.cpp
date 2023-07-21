//The complete Implementation of singly linked list which can be implemented..........................
#include<bits/stdc++.h>
using namespace std;
//Implementation of Singly LinkedList using class and objects
class Node{
    public:
    int data;
    Node* next;
    //contructor
    Node(int data){
      this->data = data;
      this->next = NULL;
    }
    //destructor 
    ~Node(){
        int val = this->data;
        //Memory free
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data "<<val<<endl;
    }
};

//In my code i am not handling the head == NULL if in start its //NULL then i just have to write if and else in 
//in my InsertionAtHead and InsertionAtLast in if condition the code will be
//if(head==NULL){
//   Node* temp = new Node(d);
//   head = temp
//}
//This will be the only code i have to write for hndling this condition.

//Insertion in starting or head in singly linked list.
void InsertAtHead(Node* &head,int d){//In this we passed the head with reference which means its original head not copy.
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;//The head will always pointing at first.
}
//Insertion in last or tail in singly linked list.
void InsertAtLast(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;//The tail will be always pointing at last.
}
//Insertion at any index or position.
void InsertAtAnyIndex(Node* &tail,Node* &head,int pos,int d){
    if(pos==1){
        InsertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt<pos-1){//Doing search for that certain position
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        InsertAtLast(tail,d);
        return;
    }
    Node* NodeToInsert = new Node(d);
    NodeToInsert->next = temp->next; //In this the node which want to insert its pointer will point previous nodes->next.
    temp->next = NodeToInsert;
}
//Deletion in Anyindex of the singly linked list.
void DeletionAtAnyIndex(Node* &head,int pos){
    //Deleting the first or start node.
    if(pos==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        //mememory free of first or start node using delete keyword
        delete(temp);
    }
    else{
        //Deleting the middle or last index of the singly linked list.
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<=pos-1){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
//DeletionAtAnyVal in this we will be given val which we have to delete.
void DeletionAtAnyVal(Node* &head,int val){
    //Deleting the first or start node.
    if(val==head->data){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        //mememory free of first or start node using delete keyword
        delete(temp);
    }
    else{
        //Deleting the middle or last index of the singly linked list.
        Node* curr = head;
        Node* prev = NULL;
        while(curr->data!=val){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
//Priniting in a singly linked list.
void print(Node* &head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
//Calculating the size of the Singly linked list.
int CalSize(Node* &head){
    Node* temp = head;
    int size = 0;
    while(temp!=NULL){
        size++;
        temp = temp->next;
    }
    cout<<"The size of the singly linked list is "<<size<<"."<<endl;
    return size;
}
//Searching in a singly linked list.
void SearchInSLL(Node* &head,int val,int size){
    Node* temp = head;
    while(size!=0){
        if(temp->data==val){
            cout<<"The val "<<val<<" is found in the linked list."<<endl;
            break;
        } 
        else{
            temp = temp->next;
        }
        size--;
    }
}
int main(){
    Node* node1 = new Node(5); //Creating in heap mememory(dynamic) thats why used Node*.
    //cout<<LinkedList->data<<endl;
    //cout<<LinkedList->next<<endl;
    Node* head = node1;
    Node* tail = node1;
    InsertAtHead(head,12);
    InsertAtHead(head,10);
    //print(head);
    InsertAtLast(tail,20);
    InsertAtLast(tail,30);
    InsertAtLast(tail,40);
    print(head);
    cout<<endl;
    InsertAtAnyIndex(tail,head,4,15);
    InsertAtAnyIndex(tail,head,8,45);
    InsertAtAnyIndex(tail,head,1,2);
    print(head);
    cout<<endl;
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    DeletionAtAnyIndex(head,9);
    print(head);
    cout<<endl;
    DeletionAtAnyVal(head,15);
    print(head);
    cout<<endl;
    int size;
    size = CalSize(head);
    SearchInSLL(head,30,size);
    return 0;
}