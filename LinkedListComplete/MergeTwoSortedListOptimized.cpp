#include<bits/stdc++.h>
using namespace std;
//Merge Two sorted list problem solving in the optimized way............
class Node{
  public:
  int data;
  Node* next = NULL;
  Node(int data){
      this->data = data;
      this->next = NULL;
  }
};
void insertionAtHead(Node* &head,int d){
    if(head==NULL){
        Node* temp = new Node(d);
        head =  temp;
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
//One way to merge the sorted list.
Node* mergeSortedList_1(Node* head1,Node* head2){
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    
    Node* pt = head1;
    if(head1->data>head2->data){
        pt = head2;
        head2 = head2->next;
    }else{
        head1 = head1->next;
    }
    Node* curr = pt;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            curr->next = head1;
            head1 = head1->next;
        }
        else{
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    if(head1==NULL){
        curr->next = head2;
    }
    else{
        curr->next = head1;
    }
    return pt;
}
//second way to merge the sorted list
Node* merge(Node* list1,Node* list2){
    //checking if there is ony one element in the list
    if(list1->next==NULL){
        list1->next = list2;
        return list1;
    }
    //Now if there more elements
    //Making pointers
    Node* curr1 = list1;
    Node* next1 = curr1->next;
    Node* curr2 = list2;
    Node* next2 = curr2->next;
    
    //now doing the condition chcek with loop
    while(next1!=NULL && curr2!=NULL){
        if((curr2->data>=curr1->data)&&(curr2->data<=next1->data)){
            //now if the codition is true
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            
            //Updating the pointer
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            //if the codition is not satisfied than we have to increment the pointer
            curr1 = next1;
            next1 = next1->next;
            //if the next1==NULL then we will point the curr1->next to the curr2
            if(next1==NULL){
                curr1->next = curr2;
                return list1;
            }
        }
    }
    return list1;
}
Node* mergeSortedList_2(Node* list1,Node* list2){
    if(list1==NULL)return list2;
    if(list2==NULL)return list1;
    
    if(list1->data<=list2->data){
        return merge(list1,list2);
    }
    else{
        return merge(list2,list1);
    }
}
int main(){
    Node* head1 = NULL;
    insertionAtHead(head1,5);
    insertionAtHead(head1,4);
    insertionAtHead(head1,1);
    print(head1);
    Node* head2 = NULL;
    insertionAtHead(head2,5);
    insertionAtHead(head2,3);
    insertionAtHead(head2,2);
    print(head2);
    Node* ans = mergeSortedList_1(head1,head2);
    print(ans);
    Node* ans2 = mergeSortedList_2(head1,head2);
    print(ans2);
    return 0;
}