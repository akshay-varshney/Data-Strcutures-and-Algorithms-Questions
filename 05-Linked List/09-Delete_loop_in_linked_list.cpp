// Linked List: Delete loop in linkedlist
//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

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
// Insertion of node at the start of linked list. Updating the address of the head pointer to the new head.
Node* Insert_start(Node *head, int data){
    Node* temp = new Node();
    temp->data=data;
    temp->next = head;
    temp->flag=0;
    head = temp;
    return head;
}
// Making a cycle in Linked List
void make_cycle(Node *&head, int pos){
    Node *temp=head;
    int count=1;
    Node *startNode=NULL;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}

// Removing a cycle by using hare and tortoise method
void remove_loop(Node *&head){
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    Node *first=head;
    while(slow!=NULL && first->next!=slow->next){
        first=first->next;
        slow=slow->next;
    }
    if(slow!=NULL){
        slow->next=NULL;
    }
}

// Check whether cycle exsist in linked List or not
bool detect_cycle(Node *&head){
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
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
    make_cycle(head, 3);
    cout<<detect_cycle(head)<<endl;
    remove_loop(head);
    cout<<detect_cycle(head)<<endl;
    Print_Linked_list(head);
}
