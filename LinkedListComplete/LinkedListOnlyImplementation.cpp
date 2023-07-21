#include<bits/stdc++.h>
using namespace std;
//Implementation of Singly LinkedList using class and objects
class Node{
    public:
    int data;
    Node* next;
    //contructor
    Node(int data){
      this->data = data;
      this->next = NULL;
    }
};
//Only head Node for now.
int main(){
    Node* head = new Node(5); //Creating in heap mememory(dynamic) thats why used Node*.
    cout<<LinkedList->data<<endl;
    cout<<LinkedList->next<<endl;
    return 0;
}