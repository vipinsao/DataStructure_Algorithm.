#include<bits/stdc++.h>
using namespace std;
//The problem is Reversing the singly linked list using two approaches but recursing printing is not working. 
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void InsertionAtHead(Node* &head,int d){
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
//In Iterative way using while loop. TimeComplexity O(n) and SpaceComplexity O(1).
Node* ReverseLinkedList(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
//Recusrive solution :- TimeComplexity O(n) and SpaceComplexity O(n*k) due to stack call.
Node* ReverseLinkedListUsingRecursion(Node* head){
    //base case.
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node* chhotaHead = ReverseLinkedListUsingRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return chhotaHead;
}
void 
int main(){
    Node* head = NULL;
    InsertionAtHead(head,5);
    InsertionAtHead(head,4);
    InsertionAtHead(head,3);
    InsertionAtHead(head,2);
    InsertionAtHead(head,1);
    print(head);
    Node* newHead;
    newHead = ReverseLinkedList(head);
    cout<<"Reversing the linked list using iterative solution :- "<<endl;
    print(newHead);
    Node* newHead1;
    newHead1 = ReverseLinkedListUsingRecursion(head);
    cout<<"Reversing the linked list using recusrive solution :- "<<endl;
    print(newHead1);
    return 0;
}