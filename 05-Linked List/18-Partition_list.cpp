// Linked List:Partition List
//https://www.interviewbit.com/problems/partition-list/

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

// Maintain 2 pointers - one which maintains all nodes less than x and another which maintains nodes greater than or equal to x.
//Keep going along our list. When we are at node that is greater than or equal to x, we remove this node from our list and move it to list of nodes greater than x.
Node *partition(Node * &head, int value){
    Node *first=new Node();
    Node *last=new Node();
    Node *f=first;
    Node *l=last;
    Node *temp=head;
    while(temp!=NULL){
        if(temp->data <value){
            first->next=temp;
            first=first->next;
            
        }
        else{
            last->next=temp;
            last=last->next;
        }
        temp=temp->next;
    }
    last->next=NULL;
    first->next=l->next;
    return f->next;
}


int main() {
    Node *head=new Node();
    head=NULL;
    append(head, 1);
    append(head, 4);
    append(head, 3);
    append(head, 2);
    append(head, 5);
    append(head, 2);
    Print_Linked_list(head);
    partition(head,3);
    Print_Linked_list(head);
}

