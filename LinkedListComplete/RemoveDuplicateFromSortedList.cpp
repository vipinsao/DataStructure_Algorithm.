#include<bits/stdc++.h>
using namespace std;

//RemoveDuplicate From SORTED Linked list.
//The very optimized solution it can also be solved in different ways like using hashing(map).
//TimeComplexity O(n) and spaceComplexity O(1).

Node* RemoveDuplicateInSortedList(Node* head){
    Node* curr = head;
    while(curr!=NULL){
        if(curr->data==curr->next->data){//checking if the curr ka data equal hai ki nahi uske aagle node ke data se
            Node* next_next = curr->next->next;//agar equal hai toh curr ko phir uske next ke next me shift karna hoga
            Node* nodeToDelete = curr->next;//aur hume curr ke next ko delete marna hoga jo ki ye code se hum samjh sakte hai.
            delete(nodeToDelete);
            curr->next = next_next;
        }
        else{
            curr = curr->next;//If the data is not equal then increment the curr.
        }
    }
    return head;
}