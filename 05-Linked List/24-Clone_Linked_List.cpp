// LinkedList: Clone a linked list with next and random pointer in O(1) space
//https://www.geeksforgeeks.org/clone-linked-list-next-random-pointer-o1-space/


#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;
};

void Print_Linked_list(Node *n)
{
    while(n!=nullptr){
        cout<<"Data: "<<n->data<<" Random: "<<n->random->data<<endl;
        n=n->next;
    }
    cout<<endl;
}

// Insertion of node at the head of linked list. Updating the address of the head pointer to the new head.
Node* Insert_head(Node *head, int data)
{
    Node* temp = new Node();
    temp->data=data;
    temp->next = head;
    head = temp;
    return head;
}
/*
 3 steps:
 1. Creating a copy of current element and linking the next of current element with it's copy
 2. Checking the random of current and copying the random into copies by using it's next
 3. Seprating the current element and copied elements
 */
Node* duplicate(Node* &head)
{
    Node * current = head;
    while(current!=NULL)
    {
        Node *temp = current->next;
        current->next = new Node();
        current->next->data = current->data;
        current->next->next = temp;
        current =temp;
    }
    current =head;
    
    while(current!=NULL)
    {
        if(current->next!=NULL)
        {
            if(current->random!=NULL)
                current->next->random = current->random->next;
            else
                current->next->random =NULL;
        }
        current =current->next->next;
    }
    
    
    Node *First = head;
    Node *duplicate = head->next;
    Node *temp =duplicate;
    while(First!=NULL && duplicate->next)
    {
        First->next =First->next->next;
        duplicate->next =duplicate->next->next;
        First =First->next;
        duplicate = duplicate->next;
    }
    return temp;
}

int main()
{
    Node *head=new Node();
    head=NULL;
    head=Insert_head(head, 5);
    head=Insert_head(head, 4);
    head=Insert_head(head, 3);
    head=Insert_head(head, 2);
    head=Insert_head(head, 1);
    // 1's random points to 3
    head->random = head->next->next;
 
    // 2's random points to 1
    head->next->random = head;
 
    // 3's and 4's random points to 5
    head->next->next->random =
                    head->next->next->next->next;
    head->next->next->next->random = head->next->next->next->next;
 
    // 5's random points to 2
    head->next->next->next->next->random = head->next;
    Print_Linked_list(head);
    auto ans= duplicate(head);
    Print_Linked_list(ans);
  
}
