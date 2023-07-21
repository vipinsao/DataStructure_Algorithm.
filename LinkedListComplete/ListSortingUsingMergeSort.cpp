#include<bits/stdc++.h>
using namespace std;
//Sorting the linked list uisng the optimal MergeSort algorithm. TimeComplexity O(nlogn), SpaceComplexity O(n).
class Node{
  public:
  int data;
  Node* next;
  Node(int data){
      this->data = data;
      this->next = NULL;
  }
};
void insertionAtHead(Node* &head,int d){
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
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
//For finding the mid element in list.
Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//In this we will be creating a dummy node in this node we will merge the sorted list.
Node* merge(Node* list1,Node* list2){
    if(list1==NULL)return list2;
    if(list2==NULL)return list1;
    Node* dummy = new Node(-1);//created dummy node thats why used -1 as value.
    Node* temp = dummy;
    while(list1!=NULL && list2!=NULL){//Until list1 or list2 is not equal to NULL keep going.
        if(list1->data<=list2->data){
            temp->next = list1;//It will store the list1's pointing element's value.
            temp = list1;//Now temp will point to the list1.
            list1 = list1->next;
        }
        else{
            temp->next = list2;//It will store the list1's pointing element's value.
            temp = list2;//Now temp will point to the list1.
            list2 = list2->next;
        }
    }
    while(list1!=NULL){
        temp->next = list1;
        temp = list1;
        list1 = list1->next;
    }
    while(list2!=NULL){
        temp->next = list2;
        temp = list2;
        list2 = list2->next;
    }
    return dummy->next;//because in starting dummy will be pointing to -1 thats why used dummy->next it will be pointing
                       //The starting node of the merged and sorted list.
}
Node* MergeSort(Node* head){
    if(head==NULL || head->next==NULL)return head;
    Node* mid = findMid(head);
    
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;//for dividing the list in two halves we had to do mid->next = NULL.
    
    left = MergeSort(left);//it will sort the left half of the list.
    right = MergeSort(right);//it will sort the right of the list.
    
    Node* ans = merge(left,right);//it will merge and return the merged list.
    return ans;
}
int main(){
    Node* head = NULL;
    insertionAtHead(head,7);
    insertionAtHead(head,2);
    insertionAtHead(head,4);
    insertionAtHead(head,1);
    insertionAtHead(head,10);
    insertionAtHead(head,3);
    insertionAtHead(head,5);
    print(head);
    Node* newHead = MergeSort(head);
    print(newHead);
    return 0;
}