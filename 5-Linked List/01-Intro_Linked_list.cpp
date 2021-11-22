//Linked List: Traveral and Printing of node

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
        cout<<n->data<<" ";
        n=n->next;
    }
}

// Creating nodes, adding data and printing nodes.
int main(){
    Node *head=nullptr;
    Node *first=nullptr;
    Node *second=nullptr;
    head=new Node();
    first=new Node();
    second= new Node();
    head->data=1;
    head->next=first;
    first->data=2;
    first->next=second;
    second->data=3;
    Print_Linked_list(head);
}
