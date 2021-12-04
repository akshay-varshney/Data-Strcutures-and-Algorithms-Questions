// Linked List: Check if a linked list is a palindrome or not
//https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/

#include <iostream>

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

// Append nodes at the end of the linked list.
void append(Node *&head, int data){
    Node *newnode=new Node();
    newnode->next=NULL;
    newnode->data=data;
    Node *last=head;
    if(head==NULL){
        head=newnode;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newnode;
    return;
}
// Reversing the linked list
Node * reverse(Node *head){
    Node *temp=head;
    Node *prev=NULL;
    Node *Next;
    while(temp!=NULL){
        Next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=Next;
    }
    head=prev;
    return head;
}

bool ispallindrome(Node *head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node *slow=head;
    Node *fast=head;
    Node *temp=head;
    // Traversing linked list and finding the middle element of the linked list
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverse(slow->next); // reversing the linked list after slow pointer
    slow=slow->next;
    // trversing while slow is not NULL. This will work for both odd and even case
    while(slow!=NULL){
        if(temp->data!=slow->data){
            return false;
        }
        temp=temp->next;
        slow=slow->next;
    }
    return true;
}
int main() {
    Node *head=new Node();
    head=NULL;
    append(head, 4);
    append(head, 2);
    append(head, 12);
    append(head, 2);
    append(head, 4);
    Print_Linked_list(head);
    cout<<ispallindrome(head)<<endl;
}

