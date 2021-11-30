// Linked List: Intersection of two linked list
//https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

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
// Intersection of two linked list 
Node * Intersection(Node *&head1, Node *&head2){
    Node *temp1=head1;
    Node *temp2=head2;
    Node *output=new Node();
    output=NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data==temp2->data){
            append(output, temp2->data);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp2->data>temp1->data){
            temp1=temp1->next;
        }
        else{
            temp2=temp2->next;
        }
    }
    return output;
}

int main() {
    Node *head=new Node();
    head=NULL;
    head=Insert_start(head, 6);
    head=Insert_start(head, 4);
    head=Insert_start(head, 3);
    head=Insert_start(head, 2);
    head=Insert_start(head, 1);
    Node *head2=new Node();
    head2=NULL;
    head2=Insert_start(head2, 18);
    head2=Insert_start(head2, 16);
    head2=Insert_start(head2, 14);
    head2=Insert_start(head2, 12);
    Print_Linked_list(head);
    Print_Linked_list(head2);
    Node *ans=Intersection(head, head2);
    Print_Linked_list(ans);
}
