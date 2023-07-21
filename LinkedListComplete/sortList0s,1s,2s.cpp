#include<bits/stdc++.h>
using namespace std;
//SortList 0s,1s and 2s problem solution without replacing the original value of the list.
//In this solution we are using the firstly make three different list for each value
//After that merge them for this we had to make dummy nodes.
//TimeComplexity O(n) and SpaceComplexity O(1).
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
void insertionAtTail(Node* &tail,Node* curr){
    tail->next = curr;
    tail = curr;
}
//The solution without replacing the original list value.
Node* SortList(Node* head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    while(curr!=NULL){
        int val = curr->data;
        if(val==0){
            insertionAtTail(zeroTail,curr);
        }
        else if(val==1){
            insertionAtTail(oneTail,curr);
        }
        else if(val==2){
            insertionAtTail(twoTail,curr);
        }
        curr = curr->next;
    }
    
    //merge the 3 - list
    
    //This is condition if there is no 1s value so direct connect the zeroTail with twoHead.
    if(oneHead->next==NULL){
          zeroTail->next = twoHead->next;
    }   
    else{
        zeroTail->next = oneHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    
    //deleting the dummy nodes
    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}
int main(){
    Node* head = NULL;
    insertionAtHead(head,2);
    insertionAtHead(head,1);
    insertionAtHead(head,0);
    insertionAtHead(head,2);
    insertionAtHead(head,0);
    insertionAtHead(head,1);
    insertionAtHead(head,2);
    print(head);
    Node* newHead = SortList(head);
    print(newHead);
    return 0;
}