// Linked List: Reverse a Linked List in group of Given Size.
//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#
/*
 Input:
 LinkedList: 1->2->2->4->5->6->7->8
 K = 4
 Output: 4 2 2 1 8 7 6 5
 */
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
Node * reverse_linked_list(Node * &head, int k){
    Node *prev=NULL;
    Node *Next;
    Node *temp=head;
    int count=0;
    while(temp!=NULL && count<k){
        Next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=Next;
        count++;
    }
    // head->next will keep on iterating k+1.. elements
    if(Next!=NULL){
        Print_Linked_list(prev);
        head->next=reverse_linked_list(Next, k);
    }
    return prev;
}


int main(int argc, const char * argv[]) {
    Node *head=new Node();
    head=NULL;
    head=Insert_start(head, 6);
    head=Insert_start(head, 5);
    head=Insert_start(head, 4);
    head=Insert_start(head, 3);
    head=Insert_start(head, 2);
    head=Insert_start(head, 1);
    Print_Linked_list(head);
    head=reverse_linked_list(head,2);
    Print_Linked_list(head);
}
