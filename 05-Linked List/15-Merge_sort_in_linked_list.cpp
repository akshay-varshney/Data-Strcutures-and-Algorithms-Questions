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
//Partition and divide linked list into two parts using fast pointer and slow pointer approach
void Partition(Node *head, Node *&start, Node *&end){
    Node * fast;
    Node *slow;
    if(head==NULL || head->next==NULL){
        start=head;
        end=NULL;
    }
    else{
        slow=head;
        fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        start=head;
        end=slow->next;
        slow->next=NULL;
    }
}
// merging  the list by comparing data of divided list
Node * mergelist(Node *A, Node *B){
    Node *merge=NULL;
    if(A==NULL){
        return B;
    }
    else if(B==NULL){
        return A;
    }
    if(A->data <= B->data){
        merge=A;
        merge->next=mergelist(A->next, B);
    }
    else{
        merge=B;
        merge->next=mergelist(A, B->next);
    }
    return merge;
}

void merge_sort(Node *&head){
    Node *start=NULL;
    Node *end=NULL;
    Node *temp=head;
    if(temp==NULL && temp->next==NULL){
        return ;
    }
    Partition(temp,start,end);
    if(start->next!=NULL) merge_sort(start);
    if(end->next!=NULL) merge_sort(end);
    head=mergelist(start, end);
}

int main() {
    Node *head=new Node();
    head=NULL;
    append(head, 11);
    append(head, 2);
    append(head, 3);
    append(head, 14);
    append(head, 5);
    Print_Linked_list(head);
    merge_sort(head);
    Print_Linked_list(head);
}
