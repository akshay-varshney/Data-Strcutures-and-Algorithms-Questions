// Linked List: Remove Duplicate from Sorted List
//https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/

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

void remove_duplicate(Node *&head){
    Node *temp=head;
//    if(hea)
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            temp->next=temp->next->next;
        }
        else{
        temp=temp->next;
        }
    }
}
// Time: O(n) and Space: O(1)

int main() {
    Node *head=new Node();
    head=NULL;
//    head=Insert_start(head, 6);
    head=Insert_start(head, 3);
    head=Insert_start(head, 3);
    head=Insert_start(head, 3);
    head=Insert_start(head, 2);
    head=Insert_start(head, 2);
    Print_Linked_list(head);
    remove_duplicate(head);
    Print_Linked_list(head);
}
