//Linked List: Search element in Linked List using iterative and recursive approach

#include <iostream>

using namespace std;

// A Node class which has two values data and pointer to next node
class Node{
public:
    int data;
    Node *next;
};

//Printing elements of the linked list
void Print_Linked_list(Node *n){
    while(n!=nullptr){
        cout<<n->data<<"->";
        n=n->next;
    }
    cout<<endl;
}
// Insertion of node at the start of linked list. Updating the address of the head pointer to the new head.
Node* Insert_start(Node *head, int data){
    Node *newhead= new Node();
    newhead->data=data;
    newhead->next=head;
    head=newhead;
    return head;
}
// Search element using iterative way
bool search_element(Node *head, int x){
    if(head==NULL){
        return 0;
    }
    Node *temp=new Node();
    temp=head;
    while(temp->next!=NULL){
        if(temp->data==x){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
// search element using recursive way
bool search_recursive(Node *node, int x){
    if(node->next==NULL){
        return false;
    }
    if(node->data==x){
        return true;
    }
    else{
        return search_recursive(node->next,x);
    }
}

// Creating nodes, adding data and printing nodes.
int main(){
    Node *head=new Node();
    head=nullptr;
    head=Insert_start(head, 1);
    head=Insert_start(head, 2);
    head=Insert_start(head, 4);
    head=Insert_start(head, 6);
    Print_Linked_list(head);
    cout<<search_element(head, 16)<<endl;
    cout<<search_recursive(head,12)<<endl;
}
