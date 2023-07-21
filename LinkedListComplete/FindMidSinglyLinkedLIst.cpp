#include<bits/stdc++.h>
using namespace std;
//The problem is finding the middle element of the singly linked list.
//Its has two methods 
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int getLength(Node* head){
    int size = 0;
    while(head!=NULL){
        size++;
        head = head->next;
    }
    return size;
}
//Iterative method where TimeComplexity O(n)+O(n/2) = O(n).
//Space Complexity O(1).
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
//Iterative way 
Node* FindMiddleIterative(Node* head){
    int len = getLength(head);
    int ans = (len/2);
    int cnt = 0;
    Node* temp = head;
    while(cnt<ans){
        temp = temp->next;
        cnt++;
    }
    head = temp;
    return head;
}
//Recursive way TimeComplexity O(n) and space Complexity O(n*k) beacuse it will use some stack space.
Node* middle(Node* head){
    if(head==NULL || head->next==NULL)return head;
    Node* fast = head->next;
    Node* slow = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
Node* FindMiddleRecursivly(Node* head){
    return middle(head);
}
int main(){
    Node* head = NULL;
    insertionAtHead(head,1);
    insertionAtHead(head,2);
    insertionAtHead(head,3);
    insertionAtHead(head,4);
    insertionAtHead(head,5);
    print(head);
    cout<<getLength(head)<<endl;
    Node* newHead1 = FindMiddleIterative(head);
    print(newHead1);
    Node* newHead2 = FindMiddleRecursivly(head);
    print(newHead2);
    return 0;
}