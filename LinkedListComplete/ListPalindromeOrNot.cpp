#include<bits/stdc++.h>
using namespace std;
//The problem is to detecting that the list is palindrome or not...........
//best optimized solution
//the brute force will be to use the vector and save all the element and compare.
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
void insertionAtHead(Node* head,int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}
//This is the Function for reverseList.
Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* forward = NULL;
    while(head!=NULL){
        forward = head->next;
        head->next = prev;
        prev = head;
        head = forward;
    }
    return prev;
}
//Function for deteting if its palindrome or not. TimeComplexity is O(n/2)+O(n/2)+O(n/2) && spaceComplexity O(1).
//In this Function we have used reverseList and findMiddle function and last we compared the element to detect palindrome.
bool IsPalindrome(Node* head){
    if(head==NULL || head->next==NULL)return true;
    Node* slow = head;
    Node* fast = head;
    //Fidning finding Middle function.
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    //It will point mid and after mid will tell the function to reverseList.
    slow->next = reverseList(slow->next);
    slow = slow->next;
    
    //In this we will compare that head->data!= the reversed List data.
    while(slow!=NULL){
        if(head->data!=slow->data)return false;
        slow = slow->next;
        head = head->next;
    }
    return true;
}
int main(){
    Node* head = NULL;
    insertionAtHead(head,1);
    insertionAtHead(head,2);
    insertionAtHead(head,3);
    //insertionAtHead(head,2);
    insertionAtHead(head,1);
    print(head);
    cout<<IsPalindrome(head);
    return 0;
}