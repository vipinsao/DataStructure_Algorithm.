#include<bits/stdc++.h>
using namespace std;
//The problem Segregate Even and Odd Nodes in linked list solution 
//The best way as possible.
//In this we just had to place even node's data in left side and odd node's data right side.
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
//IN this olution i created extra list which will carry left side even and right side odd node.
Node* EvenAndOdd_Number_SeprateList(Node* head){
    Node* Even = new Node(-1);
    Node* evenPt = Even;
    Node* Odd = new Node(-1);
    Node* Oddpt = Odd;
    Node* temp = head;
    while(temp!=NULL){
        int val = temp->data;
        if(val%2==0){
            Node* node = new Node(val);
            evenPt->next = node;
            evenPt = evenPt->next;
        }
        else if(val%2==1){
            Node* node  = new Node(val);
            Oddpt->next = node;
            Oddpt = Oddpt->next;
        }
        temp = temp->next;
    }
    evenPt->next = Odd->next;
    return Even->next;
}
int main(){
    Node* head = NULL;
    insertionAtHead(head,2);
    insertionAtHead(head,1);
    insertionAtHead(head,7);
    insertionAtHead(head,4);
    insertionAtHead(head,3);
    insertionAtHead(head,5);
    insertionAtHead(head,6);
    print(head);
    Node* ans = EvenAndOdd_Number_SeprateList(head);
    print(ans);
    return 0;
}