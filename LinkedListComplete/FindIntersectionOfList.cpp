#include<bits/stdc++.h>
using namespace std;
//The Intersection problem of linked list in this we have two head nodes it means two linked list
//In a certain node they will both be pointing at same node thats the Intersection node or point we have to find that.


//better solution using hashing(set). in this solution we will firstly insert all the nodes(address not val) of list1.
//After that we will find list1's nodes in set hashing if its presrent then return node or return NULL.
//TimeComplexity O(n+m) and SpaceComplexity O(n).
Node* FindIntersection_node(Node* lis1,Node* list2){
    unordered_set<Node*> st;
    Node* a = list1;
    Node* b = list2;
    
    while(a!=NULL){
        st.insert(a);
        a = a->next;
    }
    while(b!=NULL){
        if(st.find(a)!=st.end())return b;
        b = b->next;
    }
    return NULL;
}

//Optimal solution in this we will traversing both list's head if head1 firstly ended then we will point it on list2's head and again
//traverse them simultanseouly in a certain point the head1 and head2 will meet. like we did head1 to point list2 we have to do same for
//head2 to point list1 if its ended if there is no intersection then at some point they both will point to NULL then it will be returned
//NULL. 
//TimeComplexity O(n+m) and SpaceComplexity O(1).
Node* FindIntersection_node(Node* list1,Node* list2){
    Node* a = list1;
    Node* b = list2;
    while(a!=b){
        a = a==NULL?list2:a->next;
        b = b==NULL?list1:b->next;
    }
    return a;
}






















