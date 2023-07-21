#include<bits/stdc++.h>
using namespace std;
//THE PROBLEM IS DETECT AND REMOVE FROM LINKED LIST. THE OPTIMIZED SOLUTION.
//TimeComplexity O(n) and SpaceComplexity O(1).

//Floyds detecting cycle algorithm its very optimized algorithm to detect the cycle or loop
// in the given linked list. its the concept of slow and fast pointer.
bool DetectCycle(Node* head){
    if(head==NULL)return false;
    //at starting the both slow and fast will point at head.
    Node* slow = head;
    Node* fast = head;
    //checking if the fast or fast->next is pointing to NULL or not. if its pointing then end the loop.
    //fast will be incremented by two times and slow will be incremented by one times.
    //at some point time they both will meet eachother if there will be cycle present, if there will be no cycle
    //then it will point to NULL and it will return false.
    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow==fast)return true;
    }
    return false;
}

//Getting the starting node of the loop to find this node we will just implement some extra code in the floyds detect cycle.
//this code will tell us the starting node which is start of loop using the mathematic equation
//we will be using third pointer which will at starting point to the head after finding the cycle will will increment the entry 
// as well as slow when the slow and entry will be equal to each other then its starting node, we can also do this without using the third 
//pointer just do slow reinitiallization to head and increment slow by one and also now incerement fast by one at some point 
//they will both me pointing to the same node its starting node.

Node* findStarting(Node* head){
    if(head==NULL)return NULL;
    Node* slow = head;
    Node* fast = head;
    Node* entry = head;
    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow==fast){
            while(slow!=entry){
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }
    return head;
}

//Now the third one is to remove the cycle or loop from the linked list. In this we will just make sure that starting loops 
//prev node's next should point the NULL then it will be removed.

Node* RemoveCycleFromLinkedList(Node* head){
    bool ans = DetectCycle(head);
    if(ans==false)return head;
    else{
        Node* starting = findStarting(head);
        Node* temp = starting;//making the copy of this starting pointer
        while(temp->next!=starting){//searching for the starting loops prev node.
            temp = temp->next;
        }
        temp->next = NULL;//making the next pointer NULL then the cycle will be removed.
    }
}

















