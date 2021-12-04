// Linked List:Sort Binary Linked List
//https://www.interviewbit.com/problems/sort-binary-linked-list/

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
void sort_binary(Node * &head){
    Node *temp=head;
    int count_0=0;
    int count_1=0;
    while(temp!=NULL){
        if(temp->data==0){
            count_0++;
        }
        else{
            count_1++;
        }
        temp=temp->next;
    }
    temp=head;
    while(count_0>0){
        temp->data=0;
        count_0--;
        temp=temp->next;
    }
    while(count_1>0){
        temp->data=1;
        count_1--;
        temp=temp->next;
    }
}
//Time : O(n) and space: O(1)

int main() {
    Node *head=new Node();
    head=NULL;
    append(head, 0);
    append(head, 1);
    append(head, 1);
    append(head, 1);
    append(head, 0);
    Print_Linked_list(head);
    sort_binary(head);
    Print_Linked_list(head);
    
}

