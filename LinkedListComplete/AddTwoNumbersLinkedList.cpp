#include<bits/stdc++.h>
using namespace std;
//AddTwoNumbers problem solution using the optimal approach this is only approach in my view 
//which is best the timeComplexity is O(max(m,n)) and spaceComplexity is O(n) beacuse of resultant list.
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
//for doing sum we have to do it from back side thats why did the reverse of the list.
Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
//This is the main function which will create a new list which will store the sum of two list.
//At starting it will be dummy so in last we have to return dummy->next;
Node* Add(Node* list1,Node* list2){
    Node* dummy = new Node(0);
    Node* temp = dummy;
    int carry = 0;
    while(list1!=NULL || list2!=NULL ||carry!=0){//until list1 or list2 or carry not get o/NULL
        int sum = 0;
        if(list1!=NULL){
            sum+=list1->data;
            list1 = list1->next;
        }
        if(list2!=NULL){
            sum+=list2->data;
            list2 = list2->next;
        }
        sum+=carry;  //adding carrying sum 
        carry = sum/10; //for carry we need only one left side number like in 12 we need 1 and 2 will be new node or our list.
        Node* node = new Node(sum%10); // this will get us the 2 of the upar number.
        temp->next = node; // making temp to point its new node.
        temp = temp->next;
    }
    return dummy->next;//returning the new head which will be the dummy->next;
}
//This will return the created list for the AddTwoNumbers.
Node* AddTwoNumbers(Node* list1,Node* list2){
    Node* l1 = reverse(list1);
    Node* l2 = reverse(list2);
    Node* ans = Add(l1,l2);
    Node* currAns = reverse(ans);
    return currAns;
}
int main(){
    Node* head1 = NULL;
    insertionAtHead(head1,3);
    insertionAtHead(head1,2);
    insertionAtHead(head1,1);
    print(head1);
    Node* head2 = NULL;
    insertionAtHead(head2,5);
    insertionAtHead(head2,4);
    print(head2);
    Node* ans = AddTwoNumbers(head1,head2);
    print(ans);
    return 0;
}