// Linked List: Middle Element of Linked List
//https://leetcode.com/problems/middle-of-the-linked-list/

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
Node *middle_element(Node *&head){
    Node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    count=(count/2);
    temp=head;
    int val=0;
    while(temp!=NULL && val<count){
        temp=temp->next;
        val++;
    }
    return temp;
}

int main() {
    Node *head=new Node();
    head=NULL;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);
    Print_Linked_list(head);
    Node *ans=middle_element(head);
    Print_Linked_list(ans);
}
