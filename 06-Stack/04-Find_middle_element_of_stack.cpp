// Stack: Find the middle element in a stack in O(1)
//https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next=NULL;
    Node *prev=NULL;
};

// Inheriting Node class into the  stack class.
class Stack: public Node{
    Node *head=NULL;
    Node *mid=NULL;
    int size=0;
public:
    // Pushing data inside the stack
    void push(int data){
        Node *temp= new Node();
        temp->data=data;
        temp->prev=NULL;
        temp->next=head;
        size++;
        if(head!=NULL){
            head->prev=temp;
        }
        head=temp;
        if(size==1){
            mid=temp;
        }
        // if length is even then in case of the push operation the middle elemnet would be the previous of the current node.
        else if(size%2==0){
            mid=mid->prev;
        }
    }
    
    // Pop Operation while keep track of the middle element
    int pop(){
        if(size==0){
            return -1;
        }
        Node *temp=head;
        int x=head->data;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        size--;
        if(size%2!=0){
            mid=mid->next;
        }
        free(temp);
        return x;
    }
    
    int Middle(){
        if(head==NULL){
            return -1;
        }
        return mid->data;
    }
    
    void Print_data(){
        Node *temp=head;
        if(size==0){
            cout<<"stack is empty "<<endl;
        }
        for(int i=0;i<size;i++){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};


int main(){
    Stack S2;
    S2.push(3);
    S2.push(4);
    S2.push(5);
    S2.push(14);
    S2.push(15);
    S2.push(24);
    S2.push(45);
    S2.Print_data();
    cout<<S2.Middle()<<endl;
    S2.pop();
    S2.Print_data();
    cout<<S2.Middle()<<endl;
}
