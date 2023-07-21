#include<bits/stdc++.h>
using namespace std;
//The solution for Linked list cycle II in this problem we will be given the list
//This list can have cycle if its have then we have to return the entry point or where
//this cycle starts from. for solving this problem we will be using the previous method
//which was used in to solve for finding the cycle in this problem we will just modify the method more.


//Time complexity O(n)*O(entry*n) space complexity O(1).
Node* LinkedListIIDetectCycle(Node* head){
    if(head==NULL || head->next==NULL)return NULL;
    Node* fast = head;
    Node* slow = head;
    Node* entry = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow==fast){//its means there is cycle now we have to find the entry point.
           while(slow!=entry){//this will tell us that entry point where is the cycle is starting.
               slow = slow->next;
               entry = entry->next;
           }
           return entry;
        }
    }
    return NULL;
}