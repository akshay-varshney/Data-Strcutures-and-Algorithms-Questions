//Linked List: Deletion of Node at nth position

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

// Deleting Node at particular position
Node * delete_node(Node *head, int position){
    Node *temp=new Node();
    temp=head;
    int i=0;
    if(position<1) return head;
    if (position==1){
        head=temp->next;
        delete temp;
        return head;
    }
    while(i<position-1 && temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    temp->next=(temp->next)->next;
    delete temp;
    return head;
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
    head=delete_node(head, 1);
    Print_Linked_list(head);
    delete_node(head, 2);
    Print_Linked_list(head);
}
