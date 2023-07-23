#include<bits/stdc++.h>
using namespace std;
//The problem is RotateListByK the optimized solution TimeComplexity O(n-size) and SpaceComplexity O(1).
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
//The optimal solution for the RotateListByK...
Node* RotateListByKInRightDirection(Node* head,int k){
    if(head==NULL || head->next==NULL || k==0)return head;//checking if there is one node or k==0
    Node* curr = head;//cerated one dummy head.
    int len = 1;//initialized len = 1.
    while(curr->next!=NULL){//Now until curr not becomes NULL
        len+;//it will be incremented
        curr = curr->next;
    }
    curr->next = head;//The last node will point the head now not NULL.
    k = k%len;//It will reduce the rotation within its range 
    int size = len-k;//It will give us the list size where the next node will become head and its next will become NULL so its last node. 
    while(size--)curr = curr->next;
    
    head = curr->next;//Now the new head is curr->next 
    curr->next = NULL;//And now curr->next is going to be NULL it means this is last node.
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
    Node* ans = RotateListByKInRightDirection(head,12);
    print(ans);
    return 0;
}