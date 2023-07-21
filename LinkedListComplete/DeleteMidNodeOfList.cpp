#include<bits/stdc++.h>
using namespace std;
//Delete the middle node of the linked list.
//Its best optimized way from my side.
//If the linked list size is even then middle node will be mid of next.
//If the node size is odd then we have to delete exact mid.
class Node{
  public:
  int data;
  Node* next;
  Node(int data){
      this->data = data;
      this->next = NULL;
  }
};
void insertionAtHead(Node* &head,int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
//For finding the mid element in list.
Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int getLength(Node* head){
    int len = 0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}
int main(){
    Node* head = NULL;
    insertionAtHead(head,7);
    insertionAtHead(head,2);
    insertionAtHead(head,4);
    insertionAtHead(head,1);
    insertionAtHead(head,10);
    insertionAtHead(head,3);
    insertionAtHead(head,5);
    print(head);
    Node* temp = findMid(head);
    Node* curr = head;
    int len = getLength(head);
    if(len%2==0){//if the linked list is even.
    while(curr!=temp){
        curr = curr->next;
    }
    curr->next = curr->next->next;
    }
    else{//If the linked list is odd.
        while(curr->next!=temp){
        curr = curr->next;
    }
    curr->next = curr->next->next;
    }
    print(head);
    return 0;
}