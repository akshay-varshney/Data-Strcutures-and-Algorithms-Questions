// Linked List:Insertion Sort
//https://www.interviewbit.com/problems/insertion-sort-list/

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
// Taking two pointer one that always start from head and another will keep updating to the next node of the current node

Node *Insertion_sort(Node * &head)
{
    Node *start=head->next;
    Node *temp=head;
    Node *prev=NULL;
    bool flag=false;
    while(start!=NULL)
    {
        flag=false;
        temp=head; // updating first pointer at the start of the list
        prev=NULL;
        while (temp!=start)
        {
            if(temp->data > start->data)
            {
                flag=true;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        if(flag)
        {
            // If head needs to be updated
            if(prev==NULL){
                while(temp->next!=start)
                    temp=temp->next;
                 // reaching to previous of the current node
                temp->next=start->next;
                start->next=head;
                head=start;
                start=temp->next;
            }
            else{
                while(temp->next!=start)
                    temp=temp->next;
                
                // Inserting and deleting node at the required position
                temp->next=start->next; // cutting the current node link.
                Node *PREV=prev->next; // copying the elements after prev
                prev->next=start; // connecting prev with element to be replaced.
                start->next=PREV; // connecting element next with previous next
                start=temp->next;
            }
        }
        else
            start=start->next;
    }
    return head;
}


int main()
{
    Node *head=new Node();
    head=NULL;
    append(head, 4);
    append(head, 3);
    append(head, 2);
    append(head, 10);
    append(head, 12);
    append(head, 1);
    append(head, 5);
    append(head, 65);
    Print_Linked_list(head);
    Insertion_sort(head);
    Print_Linked_list(head);
}

