#include<bits/stdc++.h>
using namespace std;
//The problem is RotateListByK the optimized solution TimeComplexity O(n) and SpaceComplexity O(1).
class Node{
   public:
   int data;
   Node* next;
   Node(int data){
       this->data = data;
       this->next = NULL;
   }
};
void insertionAtHead(Node* &head,Node* &tail,int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
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
//Left RotateListByK in left direction we just modified it. this code is similar to rotate right direction.

Node* RotateListByKInLeftDirection(Node* head, int k) {
    if(head==NULL || head->next==NULL || k==0)return head;//edge cases or base cases.
        Node* curr = head;//taking a dummy pointer 
        int len = 1;
        while(curr->next!=NULL){
            len++;//calculated the length of the list
            curr = curr->next;//curr->next is pointing to NULL it means the curr is last node now.
        }
        curr->next = head;//the curr->next which was pointing to NULL now point head.
        while(k--)curr = curr->next;//Now until k becomes zero run this loop 
        head = curr->next;//Now head will point the curr->next node as head.
        curr->next = NULL;//And curr->next will be now NULL.
        return head;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertionAtHead(head,tail,5);
    insertionAtHead(head,tail,4);
    insertionAtHead(head,tail,3);
    insertionAtHead(head,tail,2);
    insertionAtHead(head,tail,1);
    print(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    Node* ans = RotateListByKInLeftDirection(head,2);
    print(ans);
    return 0;
}