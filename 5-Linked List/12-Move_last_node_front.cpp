// Linked List: Move last element to front of a given Linked List
//https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/

#include <iostream>
#include <unordered_map>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    int flag;
};
void Print_Linked_list(Node *n){
    while(n!=nullptr){
        cout<<n->data<<"->";
        n=n->next;
    }
    cout<<endl;
}
// Insertion of node at the start of linked list. Updating the address of the head pointer to the new head.
Node* Insert_start(Node *head, int data){
    Node* temp = new Node();
    temp->data=data;
    temp->next = head;
    temp->flag=0;
    head = temp;
    return head;
}

void move_last_front(Node *&head){
    Node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node *first=temp->next;
    temp->next=NULL;
    Node *second=head;
    head=first;
    head->next=second;
}

int main() {
    Node *head=new Node();
    head=NULL;
    head=Insert_start(head, 6);
    head=Insert_start(head, 5);
    head=Insert_start(head, 4);
    head=Insert_start(head, 3);
    head=Insert_start(head, 2);
    head=Insert_start(head, 1);
    Print_Linked_list(head);
    move_last_front(head);
    Print_Linked_list(head);
}
