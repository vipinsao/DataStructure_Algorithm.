#include<bits/stdc++.h>
using namespace std;
//IMPLIMENTATION OF DOUBLY LINKED LIST....................
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
//Traversing in the doubly linked list.
void print(Node* head){//We are sending the copy of head not original beacuse we didint used & operator..
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" "<<endl;
        temp = temp->next;
    }
}
//Determining the length of doubly linked list.
int GetLength(Node* head){
    Node* temp = head;
    int size = 0;
    while(temp!=NULL){
        size++;
        temp = temp->next;
    }
    return size;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    print(head);
    cout<<"The length of doubly linked list "<<GetLength(head)<<endl;
    return 0;
}