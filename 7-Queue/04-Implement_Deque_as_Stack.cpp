// Queue: Implement Deque as Stack


#include <iostream>
//#include <queue>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *prev;
};
class DeQueue: public Node{
private:
    Node* front=NULL;
    Node* rear=NULL;
public:
    void Push(int x);
    void Pop();
    bool isEmpty(){
        return (front==NULL);
    }
    int Size();
    void Print();
};

int DeQueue::Size(){
    if(!isEmpty())
    {
        Node *temp=front;
        int length=0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
    return 0;
}


void DeQueue::Push(int x){
    Node *temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=temp;
        temp->next=temp->prev=NULL;
        return;
    }
    rear->next=temp;
    temp->next= NULL;
    temp->prev=rear;
    rear=temp;
}

void DeQueue::Pop(){
    if(!isEmpty()){
        Node *temp= rear;
        cout<<"Element Popped is: "<<temp->data<<endl;
        rear=rear->prev;
        if(rear){
            rear->next=NULL;
        }
        if(rear==NULL){
            front=NULL;
        }
        delete temp;
    }
}

void DeQueue::Print() {
    Node* temp = front;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

class Stack: public DeQueue{
public:
    void push(int data){
        Push(data);
    }
    void pop(){
        Pop();
    }
    void display(){
        Print();
    }
};

int main(){
    Stack S1;
    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    cout << "Stack: ";
    S1.display();
    S1.pop();
    cout << "Stack: ";
    S1.display();
    S1.Push(5);
    cout<<"Stack is: ";
    S1.display();
    cout<<"Stack size: "<<S1.Size()<<endl;
    cout<<"Stack is empty: "<<S1.isEmpty()<<endl;
}
