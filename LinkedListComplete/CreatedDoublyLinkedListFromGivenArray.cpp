#include<bits/stdc++.h>
using namespace std;
//Created Doubly linked list from array.
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
Node* CreateDoublyLinkedListFromArray(vector<int> &arr){
        // code here
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for(int i=1;i<arr.size();i++){
            Node* curr = new Node(arr[i]);
            temp->next = curr;
            temp = temp->next;
        }
        return head;
}
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    Node* head = CreateDoublyLinkedListFromArray(arr);
    print(head);
    return 0;
}