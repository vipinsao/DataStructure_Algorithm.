#include<bits/stdc++.h>
using namespace std;
//This is DetectLoopInLinkedList problem where we will be given head as reference and we have to find
//if there is loop it means if the last node's next is not pointing to NULL and it will be pointing
//to the previously element which is present in the list. so if it has loop we need to return true and if not return false.

//First the Brute for approach using the map in that we can store the all element and if the element is repeating
//in the map then it has loop and we will return true; TimeCompleixty O(n) and space Complexity O(n).
bool DetectLoopInLinkedList(Node* head){
    unordered_map<Node*,bool> mpp;
    while(head!=NULL){
        if(mpp.count(head)){
            return true;
        }
        else{
            mpp[head] = true;
            head = head->next;
        }
    }
    return false;
}

//second way to solve this in a optimal way its the fast and slow method 
//in this the TimeCompleixty O(n) and space Complexity O(1).
bool DetectLoopInLinkedList(Node* head){
    if(head==NULL || head->next==NULL)return head;
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        //In certain postion if it has loop then the slow and fast will be at same postion for sure.
        if(slow==fast){
            return true;
        }
    }
    return false;
}














