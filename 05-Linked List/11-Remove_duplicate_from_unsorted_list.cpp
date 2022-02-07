// Linked List: Remove Duplicate from Unsorted List
//https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/

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
//Taking two pointer current and previous when we find duplicate element then just unlink the current node and make prev>next as the current node
void remove_duplicate(Node *&head){
    Node *temp=head;
    Node *prev=NULL;
    unordered_map<int, int> m1;
    while(temp!=NULL){
        unordered_map<int, int>::iterator iter=m1.find(temp->data);
        if(iter!=m1.end()){
            prev->next=temp->next;
            delete temp;
        }
        else{
            m1.insert(std::make_pair(temp->data, 1));
            prev=temp;
        }
       
        temp=prev->next;
    }
}
// Time: O(n) and Space: O(n)

int main() {
    Node *head=new Node();
    head=NULL;
    head=Insert_start(head, 2);
    head=Insert_start(head, 2);
    head=Insert_start(head, 2);
    head=Insert_start(head, 2);
    head=Insert_start(head, 2);
    head=Insert_start(head, 5);
    Print_Linked_list(head);
    remove_duplicate(head);
    Print_Linked_list(head);
}
