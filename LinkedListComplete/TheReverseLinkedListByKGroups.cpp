#include<bits/stdc++.h>
using namespace std;
//This is ReverseLinkedListByKGroups problem its very hard problem but we solved it in easy way.
//TimeCompexity O(n) and Space Complexity O(n) beacuse of recursive call.
class Node{
    public:
    int data;
    Node* next = NULL;
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
//This is the function which will reverse the list in k groups.
//this fucntion is using iterative as well as recursive approach both together.
//There is some additional cases which we covered in starting.
//we used the previous iterative reverse function for reversing the k number of element in starting.
//After that the head will be pointing the element whose next element will be reversed by recusrion 
//so we did head->next = ReverseLinkedListByKGroups and in this we passed forward and k. forward is passed
//beacuse we need the next elements which will be reversed. 
//The if(len<k) is used to make sure that if the list is len of 6 and k is 4 then the reversed element will be only 4
//the remaining two element will be as it is that's the solution.
Node* ReverseLinkedListByKGroups(Node* &head,int k){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    if(len<k)return head;
    if(head==NULL)return NULL;
    
    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 0;
    while(curr!=NULL && cnt<k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    if(forward!=NULL){
        head->next = ReverseLinkedListByKGroups(forward,k);
    }
    return prev;
}
int main(){
    Node* head = NULL;
    InsertionAtHead(head,5);
    InsertionAtHead(head,4);
    InsertionAtHead(head,3);
    InsertionAtHead(head,2);
    InsertionAtHead(head,1);
    print(head);
    Node* newHead;
    newHead = ReverseLinkedListByKGroups(head,2);
    print(newHead);
    return 0;
}