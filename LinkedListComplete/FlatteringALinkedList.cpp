#include<bits/stdc++.h>
using namespace std;
//The solution of the Flattening a Linked list, In this problem we will be given a bunch of linked list where there will
//be one head and in head->next there will be more linked list and each linked has bottom nodes so the diagram for this
// @->@->@->@
// |  |     |
// ^  ^     ^
// @  @     @
// |
// ^
// @
//So this will look like the structure of the list we have to make this list one list which will be connect via the child pointer
//not via next pointer so we have to return the list which will have the all elements in it and the next->NULL(next should point NULL)
//and the child will be pointing the new list.
Node* mergeTwoList(Node* a,Node* b){
    Node* temp = new Node(0);//created dummy node which will store the all the list in it.
    Node* res = temp;
    while(a!=NULL && b!=NULL){
        if(a->data<b->data){
            temp->child = a;//the temp's child poniter will point the a list 
            temp = temp->child;//the temp will also point the new temp which has value in it.
            a = a->child;
        }
        else{
            temp->child = b;//the temp's child poniter will point the b list 
            temp = temp->child;//the temp will also point the new temp which has value in it.
            b = b->child;
        }
    }
    //Until the both list is not NULL.
    if(a) temp->child = a;
    else temp->child = b;
    
    return res->next;
}
Node* FlatteningAList(Node* root){
    if(root==NULL || root->next==NULL)return root;
    //this is for gfg problem solution
    root->next = FlatteningAList(root->next);
    //this is for code stduio problem solution
    Node* l2 = FlatteningAList(root->next);
    root->next = NULL;
    
    root = mergeTwoList(root,root->next)//for gfg solution.
    root = mergeTwoList(root,l2)//for code stduio.
    
    return root;
}