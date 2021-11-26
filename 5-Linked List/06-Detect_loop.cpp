//Linked List: Detect Loop in Linked List

#include <iostream>

using namespace std;

// A Node class which has three values data and pointer to next node and flag to know if node is traversed earlier or not
class Node{
public:
    int data;
    Node *next;
    int flag;
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
    newhead->flag=0;
    head=newhead;
    return head;
}

// Checking the loop by checking if linked list is already traversed or not.
bool detect_loop(Node *head){
    Node *temp=new Node();
    temp=head;
    while(temp->next!=NULL){
        if(temp->flag==1){
            return true;
        }
        temp->flag=1;
        temp=temp->next;
    }
    return false;
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
    cout<<detect_loop(head)<<endl;
    head->next->next->next->next = head;
    cout<<detect_loop(head)<<endl;
}
