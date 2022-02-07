//Linked List: Insertion of node at head, Insertion of node at  a position

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
// Insertion of node at a specific position
void Insert_after(int position, int data, Node *head){
    Node *next_node= new Node();
    next_node->data=data;
    // If position is 1 then we need to update the head pointer
    if(position==1){
        next_node->next=head;
        head=next_node;
        Print_Linked_list(head);
        return ;
    }
    Node *temp=head;
    int i=0;
    while(i<position-1 && temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    next_node->next=temp->next;
    temp->next=next_node;
    Print_Linked_list(head);
    return ;
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
    Insert_after(3, 130, head);
}
