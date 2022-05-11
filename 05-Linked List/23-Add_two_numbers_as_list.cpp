// Linked List: Add two numbers as list
//https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/*
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

 Output: 7 -> 0 -> 8
 */
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void Print_Linked_list(Node *n)
{
    Node *PREV=n;
    while(n!=nullptr)
    {
        cout<<n->data<<"-><-";
        PREV=n;
        n=n->next;
    }
    cout<<endl;
}

void Insert_start(Node *&head, int data)
{
    Node *newnode=new Node();
    newnode->data=data;
    newnode->next=head;
    newnode->prev=NULL;
    if(head!=NULL)
        head->prev=newnode;
    
}


// Append nodes at the end of the linked list.
void append(Node *&head, int data)
{
    Node *newnode=new Node();
    newnode->next=NULL;
    newnode->data=data;
    Node *last=head;
    if(head==NULL)
    {
        head=newnode;
        newnode->prev=NULL;
        return;
    }
    while(last->next!=NULL)
        last=last->next;
    
    last->next=newnode;
    newnode->prev=last;
    return;
}

Node * add_Node(Node* head, Node* head2){
    if(head==NULL)
        return head2;
    if(head2==NULL)
        return head;
    
    Node *temp1=head;
    Node *temp2=head2;
    Node *ANS=new Node();
    int carry=temp2->data+temp1->data;
    ANS->data=carry%10;
    carry=carry/10;
    Node *head3=ANS;
    temp1=temp1->next;
    temp2=temp2->next;
    while(temp1 || temp2 || carry)
    {
        Node *NEXT=new Node();
        int val;
        if(temp1 && temp2)
        {
            val=temp2->data+temp1->data+carry;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp2)
        {
            val=temp2->data+carry;
            temp2 = temp2->next;
        }
        else
        {
            val=temp1->data+carry;
            temp1 = temp1->next;
        }
        NEXT->data =val;
        if(val>=10)
        {
            carry=1;
            NEXT->data=(val)%10;
        }
        else
            carry=0;
        
        head3->next=NEXT;
        head3=head3->next;
    }
    return ANS;
}



int main() {
    Node *head=new Node();
    head=NULL;
    append(head, 12);
    append(head, 4);
    append(head, 3);
    Print_Linked_list(head);
    Node *head2=new Node();
    head2=NULL;
    append(head2, 5);
    append(head2, 6);
    append(head2, 4);
    Print_Linked_list(head2);
    Node *ans=add_Node(head, head2);
    Print_Linked_list(ans);
  
}
