// Linked List: Reverse a Linked List
#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *next;
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
           head = temp;
    return head;
}
// Linked List reversal by keeping track of the previous, current and next pointers
Node * reverse_linked_list(Node *head){
    Node *prev=new Node();
    Node *Next=new Node();
    prev=NULL;
    Node *temp=new Node();
    temp=head;
    while(temp!=NULL){
        Next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=Next;
    }
    head=prev;
    return  head;
}
// Recursive Reversal of linked List
void reverse(Node* current, Node* prev, Node** head)
{

    if (current->next==NULL) {
        *head = current;
        current->next = prev;
        return;
    }
    Node* Next = current->next;
    current->next = prev;
 
    reverse(Next, current, head);
}


int main(int argc, const char * argv[]) {
    Node *head=new Node();
    head=NULL;
    head=Insert_start(head, 1);
    head=Insert_start(head, 12);
    head=Insert_start(head, 14);
    head=Insert_start(head, 140);
    Print_Linked_list(head);
    head=reverse_linked_list(head);
    Print_Linked_list(head);
    reverse(head, NULL, &head);
    Print_Linked_list(head);
}
