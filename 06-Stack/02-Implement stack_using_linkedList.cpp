

// Stack:Implement using Linked lIst

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

Node *New_node(int data){
    Node *new_node=new Node();
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

int isEmpty(Node *head){
    return !head;
}

void push(Node* &head, int data){
    Node *temp=New_node(data);
    temp->next=head;
    head=temp;
}

int pop(Node* &head){
    if(isEmpty(head)){
        return NULL;
    }
    Node *temp=head;
    head=head->next;
    int value=temp->data;
    delete temp;
    return value;
}

int peek(Node *head){
    if(isEmpty(head)){
        return NULL;
    }
    return head->data;
}

int main(){
    Node *head=new Node();
    head=NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    cout<<pop(head)<<endl;
    cout<<peek(head)<<endl;
    while(!isEmpty(head)){
        cout<<peek(head)<<" ";
        pop(head);
        
    }
    return 0;
}
