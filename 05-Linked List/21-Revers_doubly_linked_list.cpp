// Linked List: Reversal of Doubly Linked List
//https://www.geeksforgeeks.org/reverse-a-doubly-linked-list/

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;
};
void Print_Linked_list(Node *n){
    Node *PREV=n;
    while(n!=nullptr){
        cout<<n->data<<"-><-";
        PREV=n;
        n=n->next;
    }
    cout<<endl;
}
void reverse(Node *&head){
    Node *temp=NULL;
    Node *current=head;
    while(current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    head=temp->prev;
}
void Insert_start(Node *&head, int data){
    Node *newnode=new Node();
    newnode->data=data;
    newnode->next=head;
    newnode->prev=NULL;
    if(head!=NULL){
        head->prev=newnode;
    }
}


// Append nodes at the end of the linked list.
void append(Node *&head, int data){
    Node *newnode=new Node();
    newnode->next=NULL;
    newnode->data=data;
    Node *last=head;
    if(head==NULL){
        head=newnode;
        newnode->prev=NULL;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newnode;
    newnode->prev=last;
    return;
}


int main() {
    Node *head=new Node();
    head=NULL;
    append(head, 11);
    append(head, 2);
    append(head, 3);
    append(head, 14);
    append(head, 4);
    Print_Linked_list(head);
    reverse(head);
    Print_Linked_list(head);
}
