#include<bits/stdc++.h>
using namespace std;
//>>>>>>>>>>>>>>>COMPLETE IMPLEMENTATION OF THE CIRCULAR (singly)LINKED LIST<<<<<<<<<<<<<<<
class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int val){
        data = val;
        next = NULL;
    }
    //destructor
    ~Node(){
        int val = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"The memory is free for the val "<<val<<endl;
    }
};
void print(Node* tail){
    if(tail==NULL){
        cout<<"The circular linked list is empty.";
        return;
    }
    Node* temp  = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail!=temp);
    cout<<endl;
}
//Insertion in any element's next easily.
void InsertionAtCircularLinkedList(Node* &tail,int element,int d){
    //when there is no element
    if(tail==NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        //when there is element found and we can insert next to it.
        Node* curr = tail;
        while(curr->data!=element){
            curr = curr->next;
        }
        //we got the element where we can insert.
        Node* NodeToInsert = new Node(d);
        NodeToInsert->next = curr->next;
        curr->next = NodeToInsert;
    }
}
//Deletion to any value in circular linked list.
void deletionInCirularLinkedList(Node* &tail,int val){
    if(tail==NULL){
        cout<<"The deletion cant be possible,please check it."<<endl;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data!=val){
        prev = curr;
        curr = curr->next;
              }
        prev->next = curr->next;
        //1 node present for deletion.
        if(curr==prev){
           tail = NULL;
           }
        //>=2 Node present for deletion.
        else if(tail==curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main(){
    Node* tail = NULL;
    InsertionAtCircularLinkedList(tail,1,5);
    print(tail);
    InsertionAtCircularLinkedList(tail,5,2);
    print(tail);
    InsertionAtCircularLinkedList(tail,2,6);
    print(tail);
    InsertionAtCircularLinkedList(tail,6,8);
    print(tail);
    InsertionAtCircularLinkedList(tail,5,7);
    print(tail);
    InsertionAtCircularLinkedList(tail,5,10);
    print(tail);
    deletionInCirularLinkedList(tail,5);
    print(tail);
    deletionInCirularLinkedList(tail,8);
    print(tail);
    deletionInCirularLinkedList(tail,2);
    print(tail);
    deletionInCirularLinkedList(tail,10);
    print(tail);
    deletionInCirularLinkedList(tail,7);
    print(tail);
    deletionInCirularLinkedList(tail,6);
    print(tail);
    return 0;
}