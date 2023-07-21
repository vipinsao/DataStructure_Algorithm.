#include<bits/stdc++.h>
using namespace std;

//RemoveDuplicate From UNSORTED Linked list.
//The very optimized solution it can also be solved in different ways like using hashing(map),using sorting and double loop.
//The best solution time complexity is O(n) and SpaceComplexity O(n) beacuse of hashing.
Node* RemoveDuplicateInUnSortedList(Node* head){
   unordered_map<int,int> mpp;//using the hashing(unordered_map)
   Node* curr = head;//Two pointer curr and prev.
   Node* prev = head;
   while(curr!=NULL){
       if(mpp.find(curr->data)!=mpp.end()){//Until we found the curr->data if not found then it will go to else part.
           curr = curr->next;//if found then it will increment curr and make prev as curr.
           prev->next = curr;
       }
       else{
           mpp[curr->data]++;//when the data is not present then putting in the map.
           prev = curr;// making prev as curr
           curr = curr->next;// and shifting the curr to next position
       }
   }
   return head;
}