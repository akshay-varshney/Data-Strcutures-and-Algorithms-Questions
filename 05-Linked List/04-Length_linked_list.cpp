//Linked List:Length of Linked List using Iterative and Recursive approach

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
//Lenght of linked List using iterative way
int length_linked(Node *head){
    Node *temp=new Node();
    temp=head;
    int count=1;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
// Length of linked list using recursive way
int recursive_length(Node *node){
    if(node->next==NULL){
        return 1;
    }
    else{
        return 1+ recursive_length(node->next);
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
    cout<<length_linked(head)<<endl;
    cout<<recursive_length(head)<<endl;
}
